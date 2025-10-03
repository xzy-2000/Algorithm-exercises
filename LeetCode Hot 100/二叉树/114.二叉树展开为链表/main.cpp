#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
		TreeNode *head;
	public:
		void flatten(TreeNode *root) {
			if (root == nullptr) {
				return;
			}
			flatten(root->right);
			flatten(root->left);
			root->left = nullptr;
			root->right = head; // 头插法，相当于链表的 root->next = head
			head = root; // 现在链表头节点是 root
		}

		// 层序遍历
		vector<vector<int>> levelOrder(TreeNode *root) {
			queue<TreeNode *> que;
			if (root != nullptr)
				que.push(root);
			vector<vector<int>> result;
			while (!que.empty()) {
				int size = que.size();
				vector<int> vec;
				for (int i = 0; i < size; i++) {
					TreeNode *node = que.front();
					que.pop();
					vec.push_back(node->val);
					if (node->left)
						que.push(node->left);
					if (node->right)
						que.push(node->right);
				}
				result.push_back(vec);
			}
			return result;
		}
};




int main() {
	// 构建测试用的二叉树
	//       10
	//      /  \
	//     5   -3
	//    / \    \
	//   3   2   11
	//  / \   \
	// 3  -2   1

	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);

	Solution solution;

	// 层序遍历
	vector<vector<int>> result = solution.levelOrder(root);
	// 输出层序遍历结果
	cout << "层序遍历结果:" << endl;
	for (const auto &level : result) {
		cout << "第 " << &level - &result[0] + 1 << " 层: ";
		for (int num : level) {
			cout << num << " ";
		}
		cout << endl;
	}

	solution.flatten(root);

	vector<vector<int>> result1 = solution.levelOrder(root);
	// 输出层序遍历结果
	cout << "层序遍历结果:" << endl;
	for (const auto &level : result1) {
		cout << "第 " << &level - &result[0] + 1 << " 层: ";
		for (int num : level) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}