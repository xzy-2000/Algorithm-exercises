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
		void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
			//前序遍历
			path.push_back(cur->val);//中，中为什么写在这里，因为最后一个节点也要加入到path中
			// 这才到了叶子节点
			if (cur->left == nullptr && cur->right == nullptr) { //走到了叶子节点，开始记录
				string sPath;
				for (int i = 0; i < path.size() - 1; i++) {
					sPath += to_string(path[i]);
					sPath += "->";
				}
				sPath += to_string(path[path.size() - 1]);
				result.push_back(sPath);
				return;
			}
			if (cur->left != nullptr) { // 左
				traversal(cur->left, path, result);
				path.pop_back();// 回溯
			}
			if (cur->right != nullptr) { // 右
				traversal(cur->right, path, result);
				path.pop_back();// 回溯
			}
		}
		vector<string> binaryTreePaths(TreeNode *root) {
			vector<string> result;
			vector<int> path;			//path是用来存储每一条路径的节点
			if (root == NULL)
				return result;
			// 不能在递归的函数中定义path，因为每一次递归都会重新定义一次数组
			traversal(root, path, result);
			return result;
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
	//       1
	//      / \
	//     2   2
	//    / \
	//   3   4
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
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

	vector<string> paths = solution.binaryTreePaths(root);

	for (const auto &path : paths) {
		for (auto str : path) {
			cout << str;
		}
		cout << endl;
	}

//	for (int i = 0; i < paths.size(); i++) {
//		cout << paths[i] << endl;
//
//	}
	// 释放内存
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}