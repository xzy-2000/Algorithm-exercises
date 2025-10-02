#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
	public:
		int val;
		Node *next;
		Node *random;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
		}
};


class Solution {
	public:
		Node *copyRandomList(Node *head) {
//			if (head == nullptr)
//				return nullptr;
//			Node *cur = head;
//			unordered_map<Node *, Node *> mp;
//			while (cur != nullptr) {
//				mp[cur] = new Node(cur->val);
//				cur = cur->next;
//			}
//			cur = head;
//			while (cur != nullptr) {
//				mp[cur]->next = mp[cur->next];
//				mp[cur]->random = mp[cur->random];
//				cur = cur->next;
//			}
//			return mp[head];
			if (!head)
				return nullptr;

			// ��һ�飺�����½ڵ㲢���뵽ԭ�ڵ����
			Node *curr = head;
			while (curr) {
				Node *next = curr->next;
				Node *temp = new Node(curr->val);
				curr->next = temp;
				temp->next = next;
				curr = next;
			}

			// �ڶ��飺���� random ָ��
			curr = head;
			while (curr) {
				if (curr->random) {
					curr->next->random = curr->random->next;
				}
				curr = curr->next->next;
			}

			// �����飺������������
			Node *newHead = head->next;
			curr = head;
			while (curr) {
				Node *copyNode = curr->next;
				curr->next = copyNode->next;
				if (copyNode->next) {
					copyNode->next = copyNode->next->next;
				}
				curr = curr->next;
			}

			return newHead;
		}
};

// ����������������������
Node *createTestList() {
	// �����ڵ㣺7->13->11->10->1
	Node *node1 = new Node(7);
	Node *node2 = new Node(13);
	Node *node3 = new Node(11);
	Node *node4 = new Node(10);
	Node *node5 = new Node(1);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	// ���� random ָ��
	node1->random = nullptr;
	node2->random = node1;
	node3->random = node5;
	node4->random = node3;
	node5->random = node1;

	return node1;
}

// ������������ӡ����
void printList(Node *head) {
	Node *curr = head;
	while (curr) {
		cout << "Node(" << curr->val << ")";
		if (curr->random) {
			cout << "->random(" << curr->random->val << ")";
		} else {
			cout << "->random(nullptr)";
		}
		cout << " ";
		curr = curr->next;
	}
	cout << endl;
}

// ������������֤�����Ƿ���ȷ
bool verifyCopy(Node *original, Node *copy) {
	Node *curr1 = original;
	Node *curr2 = copy;

	while (curr1 && curr2) {
		// ���ֵ�Ƿ���ͬ
		if (curr1->val != curr2->val)
			return false;

		// ��� random ָ��ָ���ֵ�Ƿ���ͬ
		if (curr1->random && curr2->random) {
			if (curr1->random->val != curr2->random->val)
				return false;
		} else if (curr1->random || curr2->random) {
			return false;  // һ��Ϊnullptr����һ����Ϊnullptr
		}

		// ����Ƿ��ǲ�ͬ�ڵ㣨�ڴ��ַ��ͬ��
		if (curr1 == curr2)
			return false;

		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	// ��������������Ƿ���ͬ
	return curr1 == nullptr && curr2 == nullptr;
}

int main() {
	Solution solution;

	// ������������
	Node *head = createTestList();

	cout << "Original list:" << endl;
	printList(head);

	// ��������
	Node *copiedHead = solution.copyRandomList(head);

	cout << "Copied list:" << endl;
	printList(copiedHead);

	// ��֤�����Ƿ���ȷ
	if (verifyCopy(head, copiedHead)) {
		cout << "? Copy is correct!" << endl;
	} else {
		cout << "? Copy is incorrect!" << endl;
	}

	// �ָ�ԭ������Ϊ�����ڸ��ƹ������޸���ԭ����
	head = createTestList();

	// ���Կ���������
	cout << "\nTesting empty list:" << endl;
	Node *emptyCopy = solution.copyRandomList(nullptr);
	if (emptyCopy == nullptr) {
		cout << "? Empty list handled correctly!" << endl;
	}

	// ����ֻ��һ���ڵ�����
	cout << "\nTesting single node list:" << endl;
	Node *singleNode = new Node(42);
	singleNode->random = singleNode;  // ָ���Լ�
	Node *singleCopy = solution.copyRandomList(singleNode);

	cout << "Original single node: ";
	printList(singleNode);
	cout << "Copied single node: ";
	printList(singleCopy);

	if (verifyCopy(singleNode, singleCopy)) {
		cout << "? Single node copy is correct!" << endl;
	}

	return 0;
}