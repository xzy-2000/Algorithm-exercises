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
		TreeNode *invertTree(TreeNode *root) {
			if (root == nullptr) {
				return nullptr;
			}
			swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
			return root;
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
					vec.emplace_back(node->val);
					if (node->left != nullptr)
						que.push(node->left);
					if (node->right != nullptr)
						que.push(node->right);
				}
				result.emplace_back(vec);
			}
			return result;
		}
};

int main(int argc, char **argv) {
	// 构建测试用的二叉树
	//       4
	//      / \
	//     2   7
	//    / \ / \
	//   1  3 6  9
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	Solution solution;

	TreeNode *NewNode = solution.invertTree(root);
	// 层序遍历
	vector<vector<int>> result = solution.levelOrder(NewNode);
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
	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}
