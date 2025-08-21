#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};


class Solution {
	public:
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
		//非完全二叉树也适用
//		int countNodes(TreeNode *root) {
//			int cnt = 0;
//			queue<TreeNode *> que;
//			if (root != nullptr)
//				que.push(root);
//			while (!que.empty()) {
//				int size = que.size();
//				for (int i = 0; i < size; i++) {
//					TreeNode *node = que.front();
//					que.pop();
//					cnt++;
//					if (node->left)
//						que.push(node->left);
//					if (node->right)
//						que.push(node->right);
//				}
//			}
//			return cnt;
//		}
		int countNodes(TreeNode *root) {
			if (root == nullptr)
				return 0;
			TreeNode *left = root->left;
			TreeNode *right = root->right;
			int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
			while (left != nullptr) {
				left = left->left;
				leftDepth++;
			}
			while (right != nullptr) {
				right = right->right;
				rightDepth++;
			}
			if (leftDepth == rightDepth)
				return (2 << leftDepth) - 1;
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
};




int main() {
	// 构建测试用的二叉树
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

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
	cout << "结点个数为 " << solution.countNodes(root);

	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}