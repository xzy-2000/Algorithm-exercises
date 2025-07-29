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
		TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
			if (root1 == nullptr)
				return root2;
			if (root2 == nullptr)
				return root1;
			// 中
			root1->val += root2->val;
			// 左
			root1->left = mergeTrees(root1->left, root2->left);
			// 右
			root1->right = mergeTrees(root1->right, root2->right);
			return root1;
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

//	vector<int> nums1 = {1, 3, 2, 5};
//	vector<int> nums2 = {2, 1, 3, null, 4, null, 7};
	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(3);
	root1->right = new TreeNode(2);
	root1->left->left = new TreeNode(5);
	/*
		    1
		   / \
		  3   2
	     /
	    5
	*/
	TreeNode *root2 = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(3);
	root2->left->right = new TreeNode(4);
	root2->right->right = new TreeNode(7);
	/*
		   2
		  / \
		 1   3
		  \   \
		   4   7
	*/
	TreeNode *root = solution.mergeTrees(root1, root2);
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}