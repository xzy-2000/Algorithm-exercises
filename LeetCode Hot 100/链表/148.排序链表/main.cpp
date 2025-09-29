#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode *head) {
	ListNode *root = head;
	while (root != nullptr) {
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}

class Solution {
	public:
		ListNode *sortList(ListNode *head) {
			if (head == nullptr || head->next == nullptr)
				return head;

			ListNode *head2 = middleNode(head);
			// 分治
			head = sortList(head);
			head2 = sortList(head2);
			return mergeTwoLists(head, head2);
		}
	private:
		// 876. 链表的中间结点（快慢指针）
		ListNode *middleNode(ListNode *head) {
			ListNode *pre = head;
			ListNode *fast = head;
			ListNode *slow = head;
			while (fast && fast->next) {
				pre = slow; // 记录 slow 的前一个节点
				slow = slow->next;
				fast = fast->next->next;
			}
			pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
			return slow;
		}

		// 21. 合并两个有序链表（双指针）
		ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
			ListNode *dummy = new ListNode(-1); // 用哨兵节点简化代码逻辑
			ListNode *cur = dummy; // cur 指向新链表的末尾
			while (list1 && list2) {
				if (list1->val < list2->val) {
					cur->next = list1;
					list1 = list1->next;
				} else {
					cur->next = list2;
					list2 = list2->next;
				}
				cur = cur->next;
			}
			cur->next = list1 ? list1 : list2; // 拼接剩余链表
			ListNode *result = dummy->next;
			delete dummy; // 释放dummy节点
			return result;
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

// 释放链表的辅助函数
void deleteLinkedList(ListNode *head) {
	while (head) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}
}

int main(int argc, char **argv) {
	Solution solution;

	vector<int> arrA = {-1, 5, 3, 4, 0};
	ListNode *head = createLinkedList(arrA, arrA.size());

	ListNode *result = solution.sortList(head);
	display(result);
	deleteLinkedList(result); // 释放内存
	return 0;
};