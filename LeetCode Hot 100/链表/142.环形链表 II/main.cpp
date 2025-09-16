#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		// 判断链表是否有环
		ListNode *detectCycle(ListNode *head) {
			ListNode *fast = head;
			ListNode *slow = head;
			while (fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow) {
					while (slow != head) {
						head = head->next;
						slow = slow->next;
					}
					return head;
				}
			}
			return nullptr;
		}
};

// 创建链表的辅助函数
ListNode *createLinkedList(vector<int> &arr, int pos) {
	if (arr.empty())
		return nullptr;

	ListNode *head = new ListNode(arr[0]);
	ListNode *current = head;
	ListNode *cycleNode = (pos == 0) ? head : nullptr;

	// 创建链表并记录可能成为环入口的节点
	for (int i = 1; i < arr.size(); i++) {
		current->next = new ListNode(arr[i]);
		current = current->next;

		if (i == pos) {
			cycleNode = current;
		}
	}

	// 如果指定了环的位置，将最后一个节点指向环入口节点
	if (pos != -1 && cycleNode != nullptr) {
		current->next = cycleNode;
	}

	return head;
}

int main() {
	Solution solution;

	vector<int> arr = {3, 2, 0, -4};
	int pos = 1; // 环的入口位置（索引从0开始）

	ListNode *head = createLinkedList(arr, pos);

	ListNode *result = solution.detectCycle(head);

	if (result) {
		cout << "true " << result->val << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}