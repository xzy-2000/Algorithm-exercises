#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����N�����ڵ�ṹ
class Node {
	public:
		int val;
		vector<Node *> children;

		Node() {}

		Node(int _val) {
			val = _val;
		}

		Node(int _val, vector<Node *> _children) {
			val = _val;
			children = _children;
		}

		int maxDepth(Node *root) {
			if (root == nullptr)
				return 0;
			int depth = 0;
			for (int i = 0; i < root->children.size(); i++) {
				depth = max(depth, maxDepth(root->children[i]));
			}
			return depth + 1;
		}

};

// ���������ӡN����
void levelOrderPrint(Node *root) {
	if (root == nullptr)
		return;

	queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();

		// ����ǰ������нڵ�
		for (int i = 0; i < levelSize; i++) {
			Node *current = q.front();
			q.pop();

			cout << current->val;
			if (i < levelSize - 1) {
				cout << ", ";
			}

			// ����ǰ�ڵ�������ӽڵ�������
			for (Node *child : current->children) {
				if (child)
					q.push(child);
			}
		}

		// ��ǰ�㴦����ϣ�����
		cout << endl;
	}
}

int main() {
	// ����ʾ��N����
	//      1
	//    / | \
	//   3  2  4
	//  / \
	// 5   6

	Node *node5 = new Node(5);
	Node *node6 = new Node(6);
	Node *node3 = new Node(3, {node5, node6});
	Node *node2 = new Node(2);
	Node *node4 = new Node(4);
	Node *root = new Node(1, {node3, node2, node4});

	// ���������ӡ��
	cout << "����������:" << endl;
	levelOrderPrint(root);
	Node node;
	cout << node.maxDepth(root) << endl;
	// �ͷ��ڴ�
	delete node5;
	delete node6;
	delete node3;
	delete node2;
	delete node4;
	delete root;

	return 0;
}