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
		TreeNode *traversal (vector<int> &preorder, vector<int> &inorder) {
			if (preorder.size() == 0)
				return nullptr;

			// 前序遍历第一个就是根节点 中
			TreeNode *root = new TreeNode(preorder[0]);

//			cout << "root " << preorder[0] << endl;
			// 叶子节点
			if (preorder.size() == 1)
				return root;

			// 找到中序遍历的切割节点
			int Index = 0;
			for (int i = 0; i < preorder.size(); i++) {
				if (inorder[i] == preorder[0]) {
					Index = i;
					break;
				}
			}
			// 左
			vector<int> leftInorder(preorder.begin() + 1, preorder.begin() + Index + 1);
//			cout << "leftInorder ";
//			for (auto num : leftInorder)
//				cout << num << " ";
//			cout << endl;

			vector<int> leftPostorder(inorder.begin(), inorder.begin() + Index);
//			cout << "leftPostorder ";
//			for (auto num : leftPostorder)
//				cout << num << " ";
//			cout << endl;
			root->left = traversal(leftInorder, leftPostorder);

			// 右
			vector<int> rightInorder(preorder.begin() + Index + 1, preorder.end());
//			cout << "rightInorder ";
//			for (auto num : rightInorder)
//				cout << num << " ";
//			cout << endl;

			vector<int> rightPostorder(inorder.begin() + Index + 1, inorder.end());
//			cout << "rightPostorder ";
//			for (auto num : rightPostorder)
//				cout << num << " ";
//			cout << endl;

			root->right = traversal(rightInorder, rightPostorder);
			return root;
		}

		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			if (inorder.size() == 0 || preorder.size() == 0)
				return nullptr;
			return traversal(preorder, inorder);
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

	vector<int> preorder = {3, 9, 20, 15, 7};
	vector<int> inorder = {9, 3, 15, 20, 7};

//	vector<int> preorder = {1, 2, 3};
//	vector<int> inorder = {2, 1, 3};

	/*
		  3
		 / \
		9  20
		  /  \
		 15   7
	*/
	TreeNode *root = solution.buildTree(preorder, inorder);
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}