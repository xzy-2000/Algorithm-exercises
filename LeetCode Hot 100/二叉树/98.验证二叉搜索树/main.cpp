#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};


class Solution {
	private:
		vector<int> vec;
		// 中序遍历
		void traversal(TreeNode *root) {
			// 终止条件
			if (root == nullptr) {
				return;
			}
			// 左
			traversal(root->left);
			// 中
			if (root != nullptr) {
				vec.push_back(root->val);
			}
			// 右
			traversal(root->right);
		}
	public:
		bool isValidBST(TreeNode *root) {
			traversal(root);
			for (int i = 1; i < vec.size(); i++) {
				if (vec[i - 1] >= vec[i])
					return false;
			}
			return true;
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
	//       4
	//      / \
	//     2   5
	//    / \
	//   1   3

	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	Solution solution;
	cout << solution.isValidBST(root) << endl;
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
	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}