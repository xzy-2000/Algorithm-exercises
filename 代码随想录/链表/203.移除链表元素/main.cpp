#include <iostream>

// ���嵥����ڵ�ṹ
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode *removeElements(ListNode *head, int val) {
			// ��������ͷ�ڵ㣬���㴦��ͷ�ڵ���ܱ�ɾ�������
			ListNode *dummyHead = new ListNode(0);
			dummyHead->next = head;
			ListNode *current = dummyHead;

			while (current->next != nullptr) {
				if (current->next->val == val) {
					// �����һ���ڵ��ֵ���� val��ɾ���ýڵ�
					ListNode *temp = current->next;
					current->next = current->next->next;
					delete temp;
				} else {
					// �����ƶ�����һ���ڵ�
					current = current->next;
				}
			}

			// ��ȡ�µ�ͷ�ڵ�
			ListNode *newHead = dummyHead->next;
			delete dummyHead;
			return newHead;
		}
};

// ������������ӡ����
void printList(ListNode *head) {
	ListNode *current = head;
	while (current != nullptr) {
		std::cout << current->val;
		if (current->next != nullptr) {
			std::cout << " -> ";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

// ������������������
ListNode *createList(int values[], int size) {
	if (size == 0)
		return nullptr;
	ListNode *head = new ListNode(values[0]);
	ListNode *current = head;
	for (int i = 1; i < size; ++i) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}

// �����������ͷ������ڴ�
void freeList(ListNode *head) {
	while (head != nullptr) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	int values[] = {1, 2, 6, 3, 4, 5, 6};
	int size = sizeof(values) / sizeof(values[0]);
	ListNode *head = createList(values, size);

	std::cout << "ԭʼ����: ";
	printList(head);

	Solution solution;
	int val = 6;
	ListNode *newHead = solution.removeElements(head, val);

	std::cout << "ɾ��ֵΪ " << val << " �Ľڵ��: ";
	printList(newHead);

	freeList(newHead);

	return 0;
}