#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode *reverseList(ListNode *head) {
			ListNode *temp;
			ListNode *cur = head;
			ListNode *pre = nullptr;
			while (cur) {
				temp = cur->next;
				cur->next = pre;
				pre = cur;
				cur = temp;
			}
			return pre;
		}
};

// 辅助函数：创建链表
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

// 辅助函数：打印链表
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
	Solution solution;
	int values[] = {1, 2, 6, 3, 4, 5, 6};
	int size = sizeof(values) / sizeof(values[0]);
	ListNode *head = createList(values, size);
	printList(head);
	ListNode *pre;
	pre = solution.reverseList(head);
	printList(pre);
	return 0;
}