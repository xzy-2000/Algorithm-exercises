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
		int ans;
		int depth(TreeNode *root) {
			// 终止条件
			if (root == nullptr) {
				return 0;
			}
			// 递归
			int L = depth(root->left); 	// 左儿子为根的子树的深度
			int R = depth(root->right); // 右儿子为根的子树的深度
			//维护每个结点的直径的最大值，会回溯
			//对每个节点:如果其左边深度与右边深度之和大于当前最大值
			//则令最大值等于它
			ans = max(ans, R + L + 1);
			//返回给更上一层的深度，回溯
			//底层->中间层->上层->更上层
			return max(L, R) + 1;
		}
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
		// 二叉树的直径
		// 某一个结点的左右子树的最大深度之和 + 1（本身） = 二叉树的直径
		int diameterOfBinaryTree(TreeNode *root) {
			ans = 1;//节点个数
			depth(root);
			return ans - 1;//结点个数-1=直径
		}
//		int diameterOfBinaryTree(TreeNode *root) {
//
//			int result = 0;
//			auto dfs = []()->int{
//
//			};
//		}
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
	cout << solution.diameterOfBinaryTree(root);
	// 释放内存
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}