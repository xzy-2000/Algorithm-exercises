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
		int ans = INT_MIN;
		int dfs(TreeNode *root) {
			if (root == nullptr) {
				return 0;
			}
			int left = dfs(root->left);
			left = max(left, 0);
			int right = dfs(root->right);
			right = max(right, 0);
			// 更新全局最大路径和：当前节点 + 左右正贡献（形成“拱形”路径）
			ans = max(ans, left + right + root->val);
			// 返回向上延伸的最大单边路径和（只能选一边）
			return root->val + max(left, right);
		}
	public:
		int maxPathSum(TreeNode *root) {
			dfs(root);
			return ans;
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
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	//      /
	//     6
	//      \	
	//		 7
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->left = new TreeNode(6);
	root->left->right->left->right = new TreeNode(7);

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
	cout << solution.maxPathSum(root);
	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}