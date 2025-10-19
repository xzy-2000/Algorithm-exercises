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
		ListNode *reverseKGroup(ListNode *head, int k) {
			// 统计节点个数
			int n = 0;
			for (ListNode *cur = head; cur; cur = cur->next) {
				n++;
			}

			ListNode dummy(0, head);
			ListNode *p0 = &dummy;
			ListNode *prev = nullptr;
			ListNode *curr = head;
			// k 个一组处理
			for (; n >= k; n = n - k) {
				for (int i = 0; i < k; i++) { // 同 92 题
					ListNode *nxt = curr->next;
					curr->next = prev;
					prev = curr;
					curr = nxt;
				}
				ListNode *nxt = p0->next;
				p0->next->next = curr;
				p0->next = prev;
				p0 = nxt;
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
	int k = 3;
	ListNode *head = createLinkedList(arrA, arrA.size());
	display(head);
	cout << endl;

	ListNode *result = solution.reverseKGroup(head, k);

	display(result);
	return 0;
}