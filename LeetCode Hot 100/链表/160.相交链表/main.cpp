#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (headA == nullptr || headB == nullptr)
				return nullptr;
			ListNode *pA = headA;
			ListNode *pB = headB;
			while (pA != pB) {
//				pA = (pA == nullptr) ? headB : pA->next;
//				pB = (pB == nullptr) ? headA : pB->next;
				// ���ƶ�ָ�룬�ټ���Ƿ���Ҫ�л�����
				if (pA == nullptr) {
					pA = headB;
				} else {
					pA = pA->next;
				}

				if (pB == nullptr) {
					pB = headA;
				} else {
					pB = pB->next;
				}

//				// �����������ӿ�ָ���飩
//				if (pA != nullptr) {
//					cout << pA->val << " ";
//				} else {
//					cout << "null ";
//				}
//
//				if (pB != nullptr) {
//					cout << pB->val << endl;
//				} else {
//					cout << "null" << endl;
//				}
			}
			return pA;
		}
};

// ��������ĸ�������
ListNode *createLinkedList(int arr[], int n) {
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

// �����ཻ����ĸ�������
void createIntersection(ListNode *headA, ListNode *headB, int intersectVal) {
	// �ҵ�����A�����һ���ڵ�
	ListNode *lastA = headA;
	while (lastA->next != nullptr) {
		lastA = lastA->next;
	}

	// �ҵ�����B��ֵΪintersectVal�Ľڵ�
	ListNode *currB = headB;
	ListNode *intersectNode = nullptr;
	while (currB != nullptr) {
		if (currB->val == intersectVal) {
			intersectNode = currB;
			break;
		}
		currB = currB->next;
	}

	// ������A�����һ���ڵ�ָ���ཻ�ڵ�
	if (intersectNode != nullptr) {
		lastA->next = intersectNode;
	}
}

int main(int argc, char **argv) {
	Solution solution;

	// �������� A: 4->1->8->4->5

	int arrA[] = {4, 1, 8, 4, 5};
	ListNode *headA = createLinkedList(arrA, 5);

	// �������� B: 5->6->1->8->4->5
	int arrB[] = {5, 6, 1, 8, 4, 5};
	ListNode *headB = createLinkedList(arrB, 6);

	// �����ཻ�ڵ㣨��ֵΪ8�Ľڵ��ཻ��
	createIntersection(headA, headB, 8);

	ListNode *result = solution.getIntersectionNode(headA, headB);

	if (result != nullptr) {
		cout << "Intersection node value: " << result->val << endl;
	} else {
		cout << "No intersection" << endl;
	}

	return 0;
}