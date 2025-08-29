#include <iostream>
using namespace std;

class MyLinkedList {
	public:
		// ��������ڵ�ṹ��
		struct ListNode {
			int val;
			ListNode *next;
			ListNode(int x): val(x), next(nullptr) {};
		};

		// ��ʼ������
		MyLinkedList() {
			_dummyHead = new ListNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
			_size = 0;
		}

		// ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
		int get(int index) {
			if (index > (_size - 1) || index < 0) {
				return -1;
			}
			ListNode *cur = _dummyHead->next;
			while (index--) { // ���--index �ͻ�������ѭ��
				cur = cur->next;
			}
			return cur->val;
		}

		// ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
		void addAtHead(int val) {
			ListNode *newNode = new ListNode(val);
			newNode->next = _dummyHead->next;
			_dummyHead->next = newNode;
			_size++;
		}

		// ��������������һ���ڵ�
		void addAtTail(int val) {
			ListNode *newNode = new ListNode(val);
			ListNode *cur = _dummyHead;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = newNode;
			_size++;
		}

		// �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
		// ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
		// ���index��������ĳ��ȣ��򷵻ؿ�
		// ���indexС��0������ͷ������ڵ�
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

		// ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
		void deleteAtIndex(int index) {
			if (index >= _size || index < 0) {
				return;
			}
			ListNode *cur = _dummyHead;
			while (index--) {
				cur = cur ->next;
			}
			ListNode *tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			//delete����ָʾ�ͷ���tmpָ��ԭ����ָ���ǲ����ڴ棬
			//��delete���ָ��tmp��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
			//������ټ���һ��tmp=nullptr,tmp���Ϊ��ָ��Ұָ��
			//���֮��ĳ���С��ʹ����tmp����ָ������Ԥ����ڴ�ռ�
			tmp = nullptr;
			_size--;
		}

		void removeElements(int val) {
			ListNode *dummyHead = new ListNode(0); // ����һ������ͷ���
			dummyHead->next = _dummyHead; // ������ͷ���ָ��head���������������ɾ������
			ListNode *cur = dummyHead;
			while (cur->next != NULL) {
				if (cur->next->val == val) {
					ListNode *tmp = cur->next;
					cur->next = cur->next->next;
					delete tmp;
				} else {
					cur = cur->next;
				}
			}
			_dummyHead = dummyHead->next;
			delete dummyHead;
		}

		// ��ӡ����
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

	// ���� addAtHead ����
	list.addAtHead(1);
	cout << "��ͷ������1������Ԫ��Ϊ: ";
	list.printLinkedList();

	// ���� addAtTail ����
	list.addAtTail(3);
	cout << "��β������3������Ԫ��Ϊ: ";
	list.printLinkedList();

	// ���� addAtIndex ����
	list.addAtIndex(1, 2);
	cout << "������1������2������Ԫ��Ϊ: ";
	list.printLinkedList();

	// ���� get ����
	cout << "����1����Ԫ��ֵΪ: " << list.get(1) << endl;

	// ���� deleteAtIndex ����
	list.deleteAtIndex(1);
	cout << "ɾ������1����Ԫ�غ�����Ԫ��Ϊ: ";
	list.printLinkedList();

	// [1,2,6,3,4,5,6]
//	list.addAtTail(1);
//	list.addAtTail(2);
//	list.addAtTail(6);
//	list.addAtTail(3);
//	list.addAtTail(4);
//	list.addAtTail(5);
//	list.addAtTail(6);
//	list.printLinkedList();
//	list.removeElements(6);
//	list.printLinkedList();
	return 0;
}