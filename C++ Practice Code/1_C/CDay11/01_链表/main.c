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
	// 1. ������㣬����ʼ�����
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->data = val;
	new_node->next = NULL;

	// 2. ������
	if (*phead == NULL) {
		*phead = new_node;
		*ptail = new_node;
		return;
	}
	
	if (val <= (*phead)->data) {
		// ͷ�巨
		new_node->next = *phead;
		*phead = new_node;
		return;
	}

	// ����Ϊ�գ�ǰ���н��
	// �ҵ���ȷ��λ�ò����� (���һ��С�� val �Ľ��)
	struct ListNode* curr = *phead;
	while (curr->next && curr->next->data < val) {
		curr = curr->next;
	} // curr->next == NULL || curr->next->data >= val
	// a. currָ�����һ����㣬 b. curr->next��ֵ��val��

	// ��curr�ĺ������new_node
	new_node->next = curr->next;
	curr->next = new_node;

	if (curr == *ptail) {
		*ptail = new_node;
	}
}

struct ListNode* middleNode1(struct ListNode* head) {
	// 1. ������ĳ���
	int n = 0;
	struct ListNode* curr = head;
	while (curr) {
		n++;
		curr = curr->next;
	} // curr == NULL

	// 2. ��������Ϊ n/2 �Ľ��
	curr = head;
	// ѭ������ʽ��currָ��Ľ�㣬����Ϊ i
	for (int i = 0; i < n / 2; i++) {
		curr = curr->next;
	} // i == n/2
	// ѭ������ʽ��currָ��Ľ�㣬����Ϊ i
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

	while (fast != NULL && fast->next != NULL) { // fast û�е���ĩβ
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			// ��һ������
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