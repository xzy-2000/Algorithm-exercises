#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x), left(left), right(right) {}
};

class Solution {
	public:
		// 返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
		// 高度用后序遍历 ： 左->右->中
		int getHeight(TreeNode *node) {
			if (node == NULL) {
				return 0;
			}
			int leftHeight = getHeight(node->left);// 左
			if (leftHeight == -1)
				return -1;
			int rightHeight = getHeight(node->right);// 右
			if (rightHeight == -1)
				return -1;
			int result;
			if (abs(leftHeight - rightHeight) > 1)// 中
				return -1;
			else
				return 1 + max(leftHeight, rightHeight);
		}

		bool isBalanced(TreeNode *root) {
			return getHeight(root) == -1 ? false : true;
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
					vec.emplace_back(node->val);
					if (node->left != nullptr)
						que.push(node->left);
					if (node->right != nullptr)
						que.push(node->right);
				}
				result.emplace_back(vec);
			}
			return result;
		}
};

int main(int argc, char **argv) {
	// 构建测试用的二叉树
	//       1
	//      / \
	//     2   2
	//    /
	//   3
	//    \
	//     4
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(4);
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
	cout << solution.isBalanced(root);
	// 释放内存
	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}