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
		// 前序遍历 中->左->右
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			if (root == NULL)
				return result;
			st.push(root);					//很重要
			while (!st.empty()) {
				TreeNode *node = st.top(); //中
				st.pop();
				result.push_back(node->val);
				if (node->right != nullptr)
					st.push(node->right);    // 右（空节点不入栈）
				if (node->left != nullptr)
					st.push(node->left);     // 左（空节点不入栈）
			}
			return result;
		}

		// 中序遍历
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			TreeNode *cur = root;
			while (cur != NULL || !st.empty()) {
				if (cur != NULL) { // 指针来访问节点，访问到最底层
					st.push(cur); // 将访问的节点放进栈
					cur = cur->left;                // 左
				} else {
					cur = st.top();
					st.pop();
					result.push_back(cur->val);	// 中
					cur = cur->right;				// 右

				}
			}
			return result;
		}

		// 后序遍历  左->右->中
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			if (root == NULL)
				return result;
			st.push(root);					//很重要
			while (!st.empty()) {
				TreeNode *node = st.top(); //中
				st.pop();
				result.push_back(node->val);
				if (node->left != nullptr)
					st.push(node->left);     // 左（空节点不入栈）
				if (node->right != nullptr)
					st.push(node->right);    // 右（空节点不入栈）
			}
			reverse(result.begin(), result.end());
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