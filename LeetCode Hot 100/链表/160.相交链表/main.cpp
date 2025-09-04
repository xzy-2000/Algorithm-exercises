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
				// 先移动指针，再检查是否需要切换链表
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

//				// 调试输出（添加空指针检查）
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

// 创建链表的辅助函数
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

// 创建相交链表的辅助函数
void createIntersection(ListNode *headA, ListNode *headB, int intersectVal) {
	// 找到链表A的最后一个节点
	ListNode *lastA = headA;
	while (lastA->next != nullptr) {
		lastA = lastA->next;
	}

	// 找到链表B中值为intersectVal的节点
	ListNode *currB = headB;
	ListNode *intersectNode = nullptr;
	while (currB != nullptr) {
		if (currB->val == intersectVal) {
			intersectNode = currB;
			break;
		}
		currB = currB->next;
	}

	// 将链表A的最后一个节点指向相交节点
	if (intersectNode != nullptr) {
		lastA->next = intersectNode;
	}
}

int main(int argc, char **argv) {
	Solution solution;

	// 创建链表 A: 4->1->8->4->5

	int arrA[] = {4, 1, 8, 4, 5};
	ListNode *headA = createLinkedList(arrA, 5);

	// 创建链表 B: 5->6->1->8->4->5
	int arrB[] = {5, 6, 1, 8, 4, 5};
	ListNode *headB = createLinkedList(arrB, 6);

	// 创建相交节点（在值为8的节点相交）
	createIntersection(headA, headB, 8);

	ListNode *result = solution.getIntersectionNode(headA, headB);

	if (result != nullptr) {
		cout << "Intersection node value: " << result->val << endl;
	} else {
		cout << "No intersection" << endl;
	}

	return 0;
}