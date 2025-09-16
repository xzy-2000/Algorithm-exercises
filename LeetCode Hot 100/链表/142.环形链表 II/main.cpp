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
		// �ж������Ƿ��л�
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

// ��������ĸ�������
ListNode *createLinkedList(vector<int> &arr, int pos) {
	if (arr.empty())
		return nullptr;

	ListNode *head = new ListNode(arr[0]);
	ListNode *current = head;
	ListNode *cycleNode = (pos == 0) ? head : nullptr;

	// ����������¼���ܳ�Ϊ����ڵĽڵ�
	for (int i = 1; i < arr.size(); i++) {
		current->next = new ListNode(arr[i]);
		current = current->next;

		if (i == pos) {
			cycleNode = current;
		}
	}

	// ���ָ���˻���λ�ã������һ���ڵ�ָ����ڽڵ�
	if (pos != -1 && cycleNode != nullptr) {
		current->next = cycleNode;
	}

	return head;
}

int main() {
	Solution solution;

	vector<int> arr = {3, 2, 0, -4};
	int pos = 1; // �������λ�ã�������0��ʼ��

	ListNode *head = createLinkedList(arr, pos);

	ListNode *result = solution.detectCycle(head);

	if (result) {
		cout << "true " << result->val << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}