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
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			// 由于可能会删除链表头部，用哨兵节点简化代码
			ListNode dummy(0, head);
			ListNode *left = &dummy;
			ListNode *right = &dummy;
			// 右指针先向右走 n 步
			while (n--) {
				right = right->next;
			}
			// 左右指针一起走
			while (right->next != nullptr) {
				right = right->next;
				left = left->next;
			}
			ListNode *temp;
			temp = left->next; // 待删除结点
			left->next = temp->next;
			delete temp;

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
	int n = 2;
	ListNode *result = solution.removeNthFromEnd(headA, n);
	display(result);
	return 0;
}