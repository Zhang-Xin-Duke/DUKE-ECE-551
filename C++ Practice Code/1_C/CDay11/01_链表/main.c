#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

struct ListNode {
	int data;
	struct ListNode* next;
};

// phead: struct ListNode**
// *phead: struct ListNode*
// **phead: struct ListNode
void add_in_sort(struct ListNode** phead, struct ListNode** ptail, int val) {
	// 1. 创建结点，并初始化结点
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->data = val;
	new_node->next = NULL;

	// 2. 插入结点
	if (*phead == NULL) {
		*phead = new_node;
		*ptail = new_node;
		return;
	}
	
	if (val <= (*phead)->data) {
		// 头插法
		new_node->next = *phead;
		*phead = new_node;
		return;
	}

	// 链表不为空，前面有结点
	// 找到正确的位置插入结点 (最后一个小于 val 的结点)
	struct ListNode* curr = *phead;
	while (curr->next && curr->next->data < val) {
		curr = curr->next;
	} // curr->next == NULL || curr->next->data >= val
	// a. curr指向最后一个结点， b. curr->next的值比val大

	// 在curr的后面插入new_node
	new_node->next = curr->next;
	curr->next = new_node;

	if (curr == *ptail) {
		*ptail = new_node;
	}
}

struct ListNode* middleNode1(struct ListNode* head) {
	// 1. 求链表的长度
	int n = 0;
	struct ListNode* curr = head;
	while (curr) {
		n++;
		curr = curr->next;
	} // curr == NULL

	// 2. 查找索引为 n/2 的结点
	curr = head;
	// 循环不变式：curr指向的结点，索引为 i
	for (int i = 0; i < n / 2; i++) {
		curr = curr->next;
	} // i == n/2
	// 循环不变式：curr指向的结点，索引为 i
	return curr;
}

struct ListNode* middleNode2(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	} // fast == NULL || fast->next == NULL

	return slow;
}

bool hasCycle(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast != NULL && fast->next != NULL) { // fast 没有到达末尾
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			// 再一次相遇
			return true;
		}
	} // fast == NULL || fast->next == NULL

	return false;
}


int main(void) {
	//struct ListNode* head = NULL;
	//struct ListNode* tail = NULL;

	//add_in_sort(&head, &tail, 9);
	//add_in_sort(&head, &tail, 5);
	//add_in_sort(&head, &tail, 2);
	//add_in_sort(&head, &tail, 7);   // 2 --> 5 --> 7 --> 9

	struct ListNode node4 = { 4, NULL };
	struct ListNode node3 = { 3, &node4 };
	struct ListNode node2 = { 2, &node3 };
	struct ListNode node1 = { 1, &node2 };  // 1 --> 2 --> 3

	struct ListNode* p = middleNode2(&node1);

	// struct ListNode node1 = { 1, NULL };

	return 0;
}