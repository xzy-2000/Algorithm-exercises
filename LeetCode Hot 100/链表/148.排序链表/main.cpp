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
		//�жϻ�������
		bool isPalindrome(ListNode *head) {
			ListNode *mid = middleNode(head);
			ListNode *head2 = reverseList(mid);
			while (head2) {
				if (head->val != head2->val) {
					return false;
				}
				head = head->next;
				head2 = head2->next;
			}
			return true;
		}
	private:
		// Ѱ���м���,ʹ�ÿ���ָ��Ѱ��
		ListNode *middleNode(ListNode *head) {
			ListNode *fast = head;
			ListNode *slow = head;
			while (fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			return slow;
		}

		// ��ת����
		ListNode *reverseList(ListNode *head) {
			ListNode *pre = nullptr, *cur = head;
			while (cur) {
				ListNode *tmp = cur->next;
				cur->next = pre;
				pre = cur;
				cur = tmp;
			}
			return pre;
		}
};

// ��������ĸ�������
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


int main(int argc, char **argv) {
	Solution solution;

	vector<int> arrA = {-1, 5, 3, 4, 0};
	ListNode *head = createLinkedList(arrA, arrA.size());

	bool result = solution.isPalindrome(head);

	if (result) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}