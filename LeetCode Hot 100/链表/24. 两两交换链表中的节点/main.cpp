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
		ListNode *swapPairs(ListNode *head) {
			ListNode dummy(0, head);
			ListNode *node0 = &dummy;
			ListNode *node1 = head;
			while (node1 != nullptr && node1->next != nullptr) {
				ListNode *node2 = node1->next;
				ListNode *node3 = node2->next;

				node0->next = node2;
				node2->next = node1;
				node1->next = node3;

				node0 = node1;
				node1 = node3;
			}
			return dummy.next;
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

	vector<int> arrA = {1, 2, 3, 4, 5};
	ListNode *headA = createLinkedList(arrA, arrA.size());
	ListNode *result = solution.swapPairs(headA);
	display(result);
	return 0;
}

