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
		void backtracking(TreeNode *root, vector<int> &result) {
			// 终止条件
			if (root == nullptr) {
				return;
			}
			// 左
			backtracking(root->left, result);
			// 中
			result.push_back(root->val);
			// 右
			backtracking(root->right, result);
		}
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			backtracking(root, result);
			return result;
		}
};

int main(int argc, char **argv) {
	// 构建测试用的二叉树
	//       1
	//      / \
	//     2   2
	//    / 	\
	//   3  	 3
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	Solution solution;
	// 层序遍历
	vector<int> result = solution.inorderTraversal(root);

	for (int num : result) {
		cout << num << " ";
	}

	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}