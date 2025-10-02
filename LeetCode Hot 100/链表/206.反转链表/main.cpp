#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode *reverseList(ListNode *head) {
			ListNode *pre = nullptr;
			ListNode *cur = head;
			while (cur != nullptr) {
				ListNode *next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			return pre;
		}
};

// 创建链表的辅助函数
ListNode *createLinkedList(vector<int> &arr, int n) {
	if (n == 0)
		return nullptr;
	ListNode *head = new ListNode(arr[0]);
	ListNode *current = head;
	for (int i = 1; i < n; i++) {
		current->next = new ListNode(arr[i]);
		current = current->next;
	}
	return head;
}

void display(ListNode *head) {
	if (head == nullptr) {
		cout << " ";
	}
	ListNode *cur = head;
	while (cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}

int main(int argc, char **argv) {
	Solution solution;

	// 创建链表 A: 4->1->8->4->5

	vector<int> arrA = {1, 2, 4, 8, 5};
	ListNode *head = createLinkedList(arrA, arrA.size());
	display(head);
	cout << endl;

	ListNode *result = solution.reverseList(head);

	display(result);
	return 0;
}