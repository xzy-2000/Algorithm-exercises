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
		ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
			ListNode *mergelist = new ListNode(0);
			ListNode *head = mergelist;
			while (list1 != nullptr && list2 != nullptr) {
				if (list1->val <= list2->val) {
					mergelist->next = list1;
					list1 = list1->next;
				} else {
					mergelist->next = list2;
					list2 = list2->next;
				}
				mergelist = mergelist->next;
			}
			if (list1 != nullptr)
				mergelist->next = list1;
			else
				mergelist->next = list2;
			return head->next;
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

	vector<int> arrA = {1, 2, 4};
	ListNode *headA = createLinkedList(arrA, arrA.size());

	// 创建链表 B: 5->6->1->8->4->5
	vector<int> arrB = {1, 3, 4};
	ListNode *headB = createLinkedList(arrB, arrB.size());

	ListNode *result = solution.mergeTwoLists(headA, headB);
	display(result);
	return 0;
}