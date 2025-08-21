#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
	public:
		ListNode *removeElements(ListNode *head, int val) {
			ListNode *dummyHead = new ListNode();
			dummyHead->next = head;
			ListNode *current = dummyHead;
			while (current->next != nullptr) {
				if (current->next->val == val) {
					ListNode *temp = current->next;
					current->next = current->next->next;
					delete temp;
				} else {
					current = current->next;
				}
			}
			// ��ȡ�µ�ͷ�ڵ�
			ListNode *newHead = dummyHead->next;
			delete dummyHead;
			return newHead;
		}
	private:
};

// ������������������
ListNode *createList(int values[], int size) {
	if (size == 0)
		return nullptr;
	ListNode *head = new ListNode(values[0]);
	ListNode *current = head;
	for (int i = 1; i < size; i++) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}

// ������������ӡ����
void printList(ListNode *head) {
	ListNode *current = head;
	while (current != nullptr) {
		cout << current->val;
		if (current->next != nullptr) {
			cout << " -> ";
		}
		current = current->next;
	}
	cout << endl;
}

int main() {
	int values[] = {1, 2, 6, 3, 4, 5, 6};
	int size = sizeof(values) / sizeof(values[0]);
	ListNode *head = createList(values, size);
	printList(head);
	Solution solution;
	int val = 6;
	ListNode *NewNode = solution.removeElements(head, val);
	printList(NewNode);
	return 0;
}