#include "BST.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}

void bst_destroy(BST* tree);

void bst_insert(BST* tree, K key) {
	// ��ȣ��������β�巨
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	// 1. ���Ҳ���λ��
	int cmp = 0;
	while (curr) {
		// �����ж�
		cmp = key - curr->key;  // ��һ�αȽϣ�
		if (cmp < 0) {
			// ������
			parent = curr;
			curr = curr->left;
		} else if (cmp > 0) {
			// ������
			parent = curr;
			curr = curr->right;
		} else {
			return;  // ��֤key��Ψһ�ԣ�
		}
	} // curr == NULL
	// 2. ������
	TreeNode* new_node = calloc(1, sizeof(TreeNode));
	new_node->key = key;

	if (!parent) {
		// ����
		tree->root = new_node;
	} else if (cmp < 0) {		// ϸ����ħ��
		parent->left = new_node;
	} else {
		parent->right = new_node;
	}
}

bool bst_search(BST* tree, K key) {
	// ��ȣ�������Ĳ���
	TreeNode* curr = tree->root;
	while (curr) {
		// �����ж�
		int cmp = key - curr->key;

		if (cmp < 0) {
			curr = curr->left;
		} else if (cmp > 0) {
			curr = curr->right;
		} else {
			return true;
		}
	} // curr == NULL
	return false;
}

void bst_delete(BST* tree, K key) {
	// 1. �ҵ�Ҫɾ���Ľ��
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	while (curr) {
		int cmp = key - curr->key;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		} else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		} else {
			// ������̣�����Խ�࣬���븴�Ӷ�Խ�ߣ�
			break;
		}
	} // curr == NULL || curr != NULL

	if (curr == NULL) return;

	// 2. ɾ��currָ����
	
	if (curr->left && curr->right) {
		// a. �˻���Ϊ2�����
		TreeNode* parentOfmin = curr;
		TreeNode* minOfRight = curr->right;
		// ������������С���
		while (minOfRight->left) {
			parentOfmin = minOfRight;
			minOfRight = minOfRight->left;
		}
		// minOfRightָ����������С�Ľ��
		curr->key = minOfRight->key;
		parent = parentOfmin;
		curr = minOfRight;
	}

	// ɾ��currָ��Ľ�� (degree: 0��1)
	TreeNode* child = curr->left ? curr->left : curr->right;
	if (!parent) {
		// ɾ�������
		tree->root = child;
	} else {
		// ��child���ӵ�parent��Ӧ��λ��
		
		// Caution: һ��Ҫ���±Ƚϣ�(��Ϊ2��������������˻�)
		// int cmp = key - parent->key; // WRONG!
		// int cmp = child->key - parent->key;	// WRONG! child����ΪNULL
		int cmp = curr->key - parent->key;
		if (cmp < 0) {
			parent->left = child;
		} else if (cmp > 0) {
			parent->right = child;
		} else {
			// cmp == 0 (��Ϊ2�����������ĸ�����������������Сֵ)
			parent->right = child;
		}
	}
	// �ͷ�curr���
	free(curr);
}


// ������ȱ���
void bst_preorder(const BST* tree);

/**********************************************************************/
/*                        �������                                     */
/**********************************************************************/
void inorder(const TreeNode* root) {
	//  1. �߽�����
	if (root == NULL) {
		return;
	}
	// 2. �ݹ鹫ʽ
	// ����������
	inorder(root->left);
	// ���������
	printf("%d ", root->key);
	// ����������
	inorder(root->right);
}

void bst_inorder(const BST* tree) {
	// ί�� (���)
	inorder(tree->root);
	printf("\n");
}

void bst_postorder(const BST* tree);

/**********************************************************************/
/*                        ��α���                                     */
/**********************************************************************/
void bst_levelorder1(const BST* tree) {
	Queue* q = queue_create();
	
	// 1. ������������
	queue_push(q, tree->root);
	// 2. �ж϶����Ƿ�Ϊ��
	while (!queue_empty(q)) {
		TreeNode* node = queue_pop(q);
		// �����ý��
		printf("%d ", node->key);
		// �ж��Ƿ�������
		if (node->left) {
			queue_push(q, node->left);
		}
		// �ж��Ƿ����Һ���
		if (node->right) {
			queue_push(q, node->right);
		}
	} // Queue EMPTY!
	printf("\n");

	queue_destroy(q);
}