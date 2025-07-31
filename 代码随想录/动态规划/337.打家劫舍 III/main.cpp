#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		int rob(TreeNode *root) {
			vector<int> result = robTree(root);
			return max(result[0], result[1]);
		}

		vector<int> robTree(TreeNode *cur) {
			if (cur == nullptr)
				return {0, 0};
			// 左
			vector<int> left = robTree(cur->left);
			// 右
			vector<int> right = robTree(cur->right);
			// 中
			// 偷cur，那么就不能偷左右节点。
			int val1 = cur->val + left[0] + right[0];
			// 不偷cur，那么可以偷也可以不偷左右节点，则取较大的情况
			int val2 = max(left[0], left[1]) + max(right[0], right[1]);
			return {val2, val1}; // 顺序不要错了
		}

		int rob1(TreeNode *root) {
			// 暴力
			if (root == nullptr)
				return 0;
			if (root->left == nullptr && root->right == nullptr) {
				return root->val;
			}
			// 偷父节点
			int val1 = root->val;
			if (root->left)
				val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left，相当于不考虑左孩子了
			if (root->right)
				val1 += rob(root->right->left) + rob(root->right->right);

			// 不偷父节点
			int val2 = rob(root->left) + rob(root->right);
			return max(val1, val2);
		}
		void levelOrder(TreeNode *root) {
			if (!root)
				return;

			queue<TreeNode *> q;
			q.push(root);

			while (!q.empty()) {
				int size = q.size();
				for (int i = 0; i < size; ++i) {
					TreeNode *node = q.front();
					q.pop();
					cout << node->val << " ";

					if (node->left)
						q.push(node->left);
					if (node->right)
						q.push(node->right);
				}
				cout << endl;  // 每一层换行（可选）
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	/*
		    3
		   / \
		  2   3
	       \   \
	        3   1
	*/
	cout << solution.rob(root) << endl;
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}