#include <iostream>

// 定义单链表节点结构
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode *removeElements(ListNode *head, int val) {
			// 创建虚拟头节点，方便处理头节点可能被删除的情况
			ListNode *dummyHead = new ListNode(0);
			dummyHead->next = head;
			ListNode *current = dummyHead;

			while (current->next != nullptr) {
				if (current->next->val == val) {
					// 如果下一个节点的值等于 val，删除该节点
					ListNode *temp = current->next;
					current->next = current->next->next;
					delete temp;
				} else {
					// 否则，移动到下一个节点
					current = current->next;
				}
			}

			// 获取新的头节点
			ListNode *newHead = dummyHead->next;
			delete dummyHead;
			return newHead;
		}
};

// 辅助函数：打印链表
void printList(ListNode *head) {
	ListNode *current = head;
	while (current != nullptr) {
		std::cout << current->val;
		if (current->next != nullptr) {
			std::cout << " -> ";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

// 辅助函数：创建链表
ListNode *createList(int values[], int size) {
	if (size == 0)
		return nullptr;
	ListNode *head = new ListNode(values[0]);
	ListNode *current = head;
	for (int i = 1; i < size; ++i) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}

// 辅助函数：释放链表内存
void freeList(ListNode *head) {
	while (head != nullptr) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	int values[] = {1, 2, 6, 3, 4, 5, 6};
	int size = sizeof(values) / sizeof(values[0]);
	ListNode *head = createList(values, size);

	std::cout << "原始链表: ";
	printList(head);

	Solution solution;
	int val = 6;
	ListNode *newHead = solution.removeElements(head, val);

	std::cout << "删除值为 " << val << " 的节点后: ";
	printList(newHead);

	freeList(newHead);

	return 0;
}