#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
// one pass

typedef struct node {
	int data;
	struct node* next;
} Node;

// 头插法
void add_node(Node* head, int val) {
	// 1. 创建结点
	Node* new_node = malloc(sizeof(Node));
	if (!new_node) {
		printf("Error: malloc failed\n");
		exit(1);
	}
	// 2. 初始化结点，并添加到链表
	new_node->data = val;
	new_node->next = head;
	
	head = new_node;
}

int main(void) {
	Node* head = NULL;

	//head = add_node(head, 3);
	//head = add_node(head, 2);
	//head = add_node(head, 1);

	add_node(head, 3);
	add_node(head, 2);
	add_node(head, 1);

	return 0;
}