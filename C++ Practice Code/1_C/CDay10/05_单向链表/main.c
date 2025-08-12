#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/* 头插 */
void add_before_head(Node** phead, Node** ptail, int val) {
	// 1. 创建结点
	Node* new_node = malloc(sizeof(Node));
	// 2. 初始化结点, 插入结点
	new_node->data = val;
	new_node->next = *phead;
	// 3. 修改head和tail的值
	*phead = new_node;
	if (*ptail == NULL) {
		*ptail = new_node;
	}
}

/* 尾插 */
void add_after_tail(Node** phead, Node** ptail, int val) {
	// 1. 创建结点
	Node* new_node = malloc(sizeof(Node));
	// 2. 初始化结点
	new_node->data = val;
	new_node->next = NULL;
	// 3. 链接结点
	if (*ptail == NULL) {
		// 插入第一个结点
		*phead = new_node;
		*ptail = new_node;
	} else {
		(*ptail)->next = new_node;
		*ptail = new_node;
	}
}

/* 按顺序插入 */
void add_by_order(Node** phead, Node** ptail, int val) {
	// 1. 创建结点
	Node* new_node = malloc(sizeof(Node));
	// 2. 初始化结点
	new_node->data = val;
	new_node->next = NULL;
	// 3. 找到插入的位置 (找第一个大于等于val的结点)
	Node* prev = NULL;
	Node* curr = *phead;
	while (curr) {
		if (curr->data >= val) {
			break;
		}
		prev = curr;
		curr = curr->next;
	} // curr == NULL || curr != NULL
	// 4. 插入结点
	if (prev == NULL) {
		new_node->next = *phead;
		// 修改head和tail
		*phead = new_node;
		if (*ptail == NULL) {
			*ptail = new_node;
		}
	} else {
		new_node->next = prev->next;
		prev->next = new_node;
		if (curr == NULL) {
			*ptail = new_node;
		}
	}
}

/* 查找第一个与特定值相等的结点 */
Node* find_by_value(const Node* head, int val) {
	// 遍历链表
	Node* curr = head;
	while (curr) {
		if (curr->data == val) {
			return curr;
		}
		curr = curr->next;
	} // curr == NULL
	return NULL;
}

/* 删除第一个与特定值相等的结点 */
void delete_by_value(Node** phead, Node** ptail, int val) {
	Node* prev = NULL;
	Node* curr = *phead;
	// 遍历链表，找到要删除的结点
	while (curr) {
		if (curr->data == val) {
			// 删除curr结点
			if (!prev) {
				// 删除第一个结点
				*phead = curr->next;
				if (*ptail == curr) {
					*ptail = NULL;
				}
			} else {
				prev->next = curr->next;
				if (*ptail == curr) {
					*ptail = prev;
				}
			}
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	} // curr == NULL
}


int main(void) {
	Node* head = NULL;
	Node* tail = NULL;

	//add_before_head(&head, &tail, 4);
	//add_before_head(&head, &tail, 3);
	//add_before_head(&head, &tail, 2);
	//add_before_head(&head, &tail, 1);	// 1 --> 2 --> 3 --> 4

	//add_after_tail(&head, &tail, 1);
	//add_after_tail(&head, &tail, 2);
	//add_after_tail(&head, &tail, 3);
	//add_after_tail(&head, &tail, 4); // 1 --> 2 --> 3 --> 4

	//add_by_order(&head, &tail, 9);
	//add_by_order(&head, &tail, 5);
	//add_by_order(&head, &tail, 2);
	//add_by_order(&head, &tail, 7);	// 2 --> 5 --> 7 --> 9

	add_before_head(&head, &tail, 9);
	add_before_head(&head, &tail, 5);
	add_before_head(&head, &tail, 2);
	add_before_head(&head, &tail, 7);	// 7 --> 2 --> 5 --> 9

	//Node* node1 = find_by_value(head, 2);
	//Node* node2 = find_by_value(head, 8);

	delete_by_value(&head, &tail, 2);
	delete_by_value(&head, &tail, 8);
	return 0;
}