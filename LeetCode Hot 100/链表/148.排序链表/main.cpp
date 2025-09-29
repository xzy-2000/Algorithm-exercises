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
			// ����
			head = sortList(head);
			head2 = sortList(head2);
			return mergeTwoLists(head, head2);
		}
	private:
		// 876. ������м��㣨����ָ�룩
		ListNode *middleNode(ListNode *head) {
			ListNode *pre = head;
			ListNode *fast = head;
			ListNode *slow = head;
			while (fast && fast->next) {
				pre = slow; // ��¼ slow ��ǰһ���ڵ�
				slow = slow->next;
				fast = fast->next->next;
			}
			pre->next = nullptr; // �Ͽ� slow ��ǰһ���ڵ�� slow ������
			return slow;
		}

		// 21. �ϲ�������������˫ָ�룩
		ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
			ListNode *dummy = new ListNode(-1); // ���ڱ��ڵ�򻯴����߼�
			ListNode *cur = dummy; // cur ָ���������ĩβ
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
			cur->next = list1 ? list1 : list2; // ƴ��ʣ������
			ListNode *result = dummy->next;
			delete dummy; // �ͷ�dummy�ڵ�
			return result;
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

// �ͷ�����ĸ�������
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
	deleteLinkedList(result); // �ͷ��ڴ�
	return 0;
};