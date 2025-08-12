#include "BST.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}

void bst_destroy(BST* tree);

void bst_insert(BST* tree, K key) {
	// 类比：单链表的尾插法
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	// 1. 查找插入位置
	int cmp = 0;
	while (curr) {
		// 条件判断
		cmp = key - curr->key;  // 作一次比较！
		if (cmp < 0) {
			// 往左走
			parent = curr;
			curr = curr->left;
		} else if (cmp > 0) {
			// 往右走
			parent = curr;
			curr = curr->right;
		} else {
			return;  // 保证key的唯一性！
		}
	} // curr == NULL
	// 2. 插入结点
	TreeNode* new_node = calloc(1, sizeof(TreeNode));
	new_node->key = key;

	if (!parent) {
		// 空树
		tree->root = new_node;
	} else if (cmp < 0) {		// 细节是魔鬼！
		parent->left = new_node;
	} else {
		parent->right = new_node;
	}
}

bool bst_search(BST* tree, K key) {
	// 类比：单链表的查找
	TreeNode* curr = tree->root;
	while (curr) {
		// 条件判断
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
	// 1. 找到要删除的结点
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
			// 软件工程：缩进越多，代码复杂度越高！
			break;
		}
	} // curr == NULL || curr != NULL

	if (curr == NULL) return;

	// 2. 删除curr指向结点
	
	if (curr->left && curr->right) {
		// a. 退化度为2的情况
		TreeNode* parentOfmin = curr;
		TreeNode* minOfRight = curr->right;
		// 找右子树的最小结点
		while (minOfRight->left) {
			parentOfmin = minOfRight;
			minOfRight = minOfRight->left;
		}
		// minOfRight指向右子树最小的结点
		curr->key = minOfRight->key;
		parent = parentOfmin;
		curr = minOfRight;
	}

	// 删除curr指向的结点 (degree: 0或1)
	TreeNode* child = curr->left ? curr->left : curr->right;
	if (!parent) {
		// 删除根结点
		tree->root = child;
	} else {
		// 将child链接到parent对应的位置
		
		// Caution: 一定要重新比较！(度为2的情况：发生了退化)
		// int cmp = key - parent->key; // WRONG!
		// int cmp = child->key - parent->key;	// WRONG! child可能为NULL
		int cmp = curr->key - parent->key;
		if (cmp < 0) {
			parent->left = child;
		} else if (cmp > 0) {
			parent->right = child;
		} else {
			// cmp == 0 (度为2，且右子树的根结点就是右子树的最小值)
			parent->right = child;
		}
	}
	// 释放curr结点
	free(curr);
}


// 深度优先遍历
void bst_preorder(const BST* tree);

/**********************************************************************/
/*                        中序遍历                                     */
/**********************************************************************/
void inorder(const TreeNode* root) {
	//  1. 边界条件
	if (root == NULL) {
		return;
	}
	// 2. 递归公式
	// 遍历左子树
	inorder(root->left);
	// 遍历根结点
	printf("%d ", root->key);
	// 遍历右子树
	inorder(root->right);
}

void bst_inorder(const BST* tree) {
	// 委托 (外包)
	inorder(tree->root);
	printf("\n");
}

void bst_postorder(const BST* tree);

/**********************************************************************/
/*                        层次遍历                                     */
/**********************************************************************/
void bst_levelorder1(const BST* tree) {
	Queue* q = queue_create();
	
	// 1. 将根结点如队列
	queue_push(q, tree->root);
	// 2. 判断队列是否为空
	while (!queue_empty(q)) {
		TreeNode* node = queue_pop(q);
		// 遍历该结点
		printf("%d ", node->key);
		// 判断是否有左孩子
		if (node->left) {
			queue_push(q, node->left);
		}
		// 判断是否有右孩子
		if (node->right) {
			queue_push(q, node->right);
		}
	} // Queue EMPTY!
	printf("\n");

	queue_destroy(q);
}