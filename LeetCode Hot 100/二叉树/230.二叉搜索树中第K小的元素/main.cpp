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
	private:
		vector<int> nums;
	public:
		// 中序遍历
		void backthroughting(TreeNode *root) {
			// 终止条件
			if (root == nullptr) {
				return;
			}
			// 左
			backthroughting(root->left);
			// 中
			nums.emplace_back(root->val);
			// 右
			backthroughting(root->right);
		}
		// 二叉搜索树
		int kthSmallest(TreeNode *root, int k) {
			backthroughting(root);
			return nums[k - 1];
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

	int k = 3;
	cout << solution.kthSmallest(root, 3);
	// 释放内存
	delete root->left->right->left;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}