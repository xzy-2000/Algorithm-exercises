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
	public:
		vector<int> rightSideView(TreeNode *root) {
			queue<TreeNode *> que;
			if (root != nullptr)
				que.push(root);
			vector<int> vec;
			while (!que.empty()) {
				int size = que.size();
				TreeNode *rightNode;
				for (int i = 0; i < size; i++) {
					rightNode = que.front();
					que.pop();
					if (rightNode->left != nullptr) {
						que.push(rightNode->left);
					}
					if (rightNode->right != nullptr) {
						que.push(rightNode->right);
					}
				}
//				cout << rightNode->val << " ";
				vec.push_back(rightNode->val);
			}
			return vec;
		}
};

int main() {
	// 构建测试用的二叉树
	//       5
	//      / \
	//     2   6
	//    / \
	//   1   4
	//      /
	//     3
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);

	Solution solution;

	vector<int> res = solution.rightSideView(root);
	for (int n : res) {
		cout << n << " ";
	}
	// 释放内存
	delete root->left->right->left;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}