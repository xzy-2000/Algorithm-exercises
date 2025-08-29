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
		// 前序遍历
		void preTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			vec.push_back(cur->val);    // 中
			preTraversal(cur->left, vec);  // 左
			preTraversal(cur->right, vec); // 右
		}

		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> result;
			preTraversal(root, result);
			return result;
		}

		// 中序遍历
		void inTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			inTraversal(cur->left, vec);  // 左
			vec.push_back(cur->val);    // 中
			inTraversal(cur->right, vec); // 右
		}

		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			inTraversal(root, result);
			return result;
		}

		// 后序遍历
		void postTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			postTraversal(cur->left, vec);  // 左
			postTraversal(cur->right, vec); // 右
			vec.push_back(cur->val);    // 中
		}

		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> result;
			postTraversal(root, result);
			return result;
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

	// 前序遍历
	vector<int> preResult = solution.preorderTraversal(root);
	cout << "前序遍历结果: ";
	for (int num : preResult)
		cout << num << " ";
	cout << endl;

	// 中序遍历
	vector<int> inResult = solution.inorderTraversal(root);
	cout << "中序遍历结果: ";
	for (int num : inResult)
		cout << num << " ";
	cout << endl;

	// 后序遍历
	vector<int> postResult = solution.postorderTraversal(root);
	cout << "后序遍历结果: ";
	for (int num : postResult)
		cout << num << " ";
	cout << endl;

	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}