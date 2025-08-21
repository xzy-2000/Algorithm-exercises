#include <iostream>
using namespace std;

class MyLinkedList {
	public:
		struct ListNode {
			int val;
			ListNode *next;
			ListNode(int x): val(x), next(nullptr) {};
		};

		// 构造函数
		MyLinkedList() {
			_dummyHead = new ListNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
			_size = 0;
		}
		// 析构函数
		~MyLinkedList() {

		}

		int get(int index) {
			if (index > (_size - 1) || index < 0) {
				return -1;
			}
			ListNode *cur = _dummyHead->next;
			while (index--) { // 如果--index 就会陷入死循环
				cur = cur->next;
			}
			return cur->val;
		}

		// 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
		void addAtHead(int val) {
			ListNode *newNode = new ListNode(val);
			newNode->next = _dummyHead->next;
			_dummyHead->next = newNode;
			_size++;
		}
		// 在链表最后面添加一个节点
		void addAtTail(int val) {
			ListNode *newNode = new ListNode(val);
			ListNode *cur = _dummyHead;
//			for (int i = 0; i <= _size; i++) {
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = newNode;
			_size++;
		}

		// 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
		// 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
		// 如果index大于链表的长度，则返回空
		// 如果index小于0，则在头部插入节点
		void addAtIndex(int index, int val) {
			if (index > _size)
				return;
			if (index < 0)
				index = 0;
			ListNode *newNode = new ListNode(val);
			ListNode *cur = _dummyHead;
			while (index--) {
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
			_size++;
		}

		// 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
		void deleteAtIndex(int index) {
			if (index >= _size || index < 0) {
				return;
			}
			ListNode *cur = _dummyHead;
			while (index--) {
				cur = cur ->next;
			}
			ListNode *tmp = cur->next;
			cur ->next = tmp->next;
			delete tmp;
			tmp = nullptr;
			_size--;
		}

		// 打印链表
		void printLinkedList() {
			ListNode *cur = _dummyHead;
			while (cur->next != nullptr) {
				cout << cur->next->val << " ";
				cur = cur->next;
			}
			cout << endl;
		}

	private:
		int _size;
		ListNode *_dummyHead;
};

int main() {
	MyLinkedList list;
	// 测试 addAtHead 函数
	list.addAtHead(1);
	cout << "在头部插入1后，链表元素为: ";
	list.printLinkedList();

	// 测试 addAtTail 函数
	list.addAtTail(3);
	cout << "在尾部插入3后，链表元素为: ";
	list.printLinkedList();

	// 测试 addAtIndex 函数
	list.addAtIndex(1, 2);
	cout << "在索引1处插入2后，链表元素为: ";
	list.printLinkedList();

	// 测试 get 函数
	cout << "索引1处的元素值为: " << list.get(1) << endl;

	// 测试 deleteAtIndex 函数
	list.deleteAtIndex(1);
	cout << "删除索引1处的元素后，链表元素为: ";
	list.printLinkedList();

//	list.addAtTail(1);
//	list.addAtTail(2);
//	list.addAtTail(6);
//	list.addAtTail(3);
//	list.addAtTail(4);
//	list.addAtTail(5);
//	list.addAtHead(6);
//	list.addAtIndex(1, 2);
//	list.printLinkedList();
	return 0;
}