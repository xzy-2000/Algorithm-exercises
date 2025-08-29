#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义N叉树节点结构
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

// 层序遍历打印N叉树
void levelOrderPrint(Node *root) {
	if (root == nullptr)
		return;

	queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();

		// 处理当前层的所有节点
		for (int i = 0; i < levelSize; i++) {
			Node *current = q.front();
			q.pop();

			cout << current->val;
			if (i < levelSize - 1) {
				cout << ", ";
			}

			// 将当前节点的所有子节点加入队列
			for (Node *child : current->children) {
				if (child)
					q.push(child);
			}
		}

		// 当前层处理完毕，换行
		cout << endl;
	}
}

int main() {
	// 构建示例N叉树
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

	// 层序遍历打印树
	cout << "层序遍历结果:" << endl;
	levelOrderPrint(root);
	Node node;
	cout << node.maxDepth(root) << endl;
	// 释放内存
	delete node5;
	delete node6;
	delete node3;
	delete node2;
	delete node4;
	delete root;

	return 0;
}