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
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//			// 迭代
//			ListNode *head = new ListNode(0);
//			ListNode *cur = head;
//			int carry = 0; // 进位
//			while (l1 != nullptr || l2 != nullptr || carry) {
//				int num1 = 0;
//				if (l1 != nullptr) {
//					num1 = l1->val;
//					l1 = l1->next;
//				}
//				int num2 = 0;
//				if (l2 != nullptr) {
//					num2 = l2->val;
//					l2 = l2->next;
//				}
//				carry += num1 + num2;
//				ListNode *newNode = new ListNode(carry % 10);  // 1. 创建新节点
//				cur->next = newNode;                          // 2. 连接新节点到链表
//				cur = newNode;                                // 3. 移动当前指针
//				carry /= 10;
//			}
//			return head->next;
			// 递归
			return backthrough(l1, l2, 0);
		}

		ListNode *backthrough(ListNode *l1, ListNode *l2, int carry) {
			// 终止条件
			if (l1 == nullptr && l2 == nullptr) {
				if (carry != 0)
					return new ListNode(carry);
				return nullptr;
			}
			int num1 = 0;
			if (l1 != nullptr) {
				num1 = l1->val;
				l1 = l1->next;
			}
			int num2 = 0;
			if (l2 != nullptr) {
				num2 = l2->val;
				l2 = l2->next;
			}
			int sum = num1 + num2;
			cout << sum << " " << carry << endl;
			return new ListNode((sum + carry) % 10, backthrough(l1, l2, (sum + carry) / 10));
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

	vector<int> arrA = {9, 9, 9, 9, 9, 9, 9};
	ListNode *headA = createLinkedList(arrA, arrA.size());

	// 创建链表 B: 5->6->1->8->4->5
	vector<int> arrB = {9, 9, 9, 9};
	ListNode *headB = createLinkedList(arrB, arrB.size());

	ListNode *result = solution.addTwoNumbers(headA, headB);
	display(result);
	return 0;
}