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
	private:
		int cnt = 0;
		bool flag = false;
	public:

		void backtracing(TreeNode *root, int targetSum) {
//			cout << "root.val = " << root->val << endl;
			// 终止条件
			if (root == nullptr) {
//				cout << "over!" << endl;
				return;
			}
			// 前序遍历
			// 中
			if (root->left == nullptr && root->right == nullptr && cnt == targetSum) {
//				cout << "targetSum = cnt = " << cnt << endl;
				flag = true;
				return;
			}
			// 左
			if (root->left != nullptr) {
				cnt += root->left->val;
//				cout << "left" << cnt << endl;
				backtracing(root->left, targetSum);
				cnt -= root->left->val;
//				cout << "left" << cnt << endl;
			}
			// 右
			if (root->right != nullptr) {
				cnt += root->right->val;
//				cout << "right" << cnt << endl;
				backtracing(root->right, targetSum);
				cnt -= root->right->val;
//				cout << "right" << cnt << endl;
			}
		}
		bool hasPathSum(TreeNode *root, int targetSum) {
			if (root == nullptr)
				return false;
			cnt += root->val;
			backtracing(root, targetSum);
			return flag;
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
	/*
			   5
			 /   \
		    4     8
		   /     / \
		  11    13  4
		 /  \		 \
		7    2 		  1
	*/
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	cout << solution.hasPathSum(root, targetSum);
	// 清理内存
	delete root->right->right;
	delete root->right->left;
	delete root->right;
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root;
	return 0;
}
/*
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
*/