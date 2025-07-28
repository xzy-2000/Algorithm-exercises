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
		TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &preorder, int preorderBegin,
		                    int preorderEnd) {
			if (preorderBegin == preorderEnd)
				return nullptr;
			// 找到根节点位置，创建根节点并写入数值
			int rootValue = preorder[preorderBegin];
			TreeNode *root = new TreeNode(rootValue);
			// 叶子节点，直接返回
			if (preorderEnd - preorderBegin == 1)
				return root;
			// 找到根节点的位置
			int mid;
			for (int i = inorderBegin; i < inorderEnd; i++) {
				if (inorder[i] == rootValue) {
					mid = i;
					break;
				}
			}
			// 切割中序遍历左右子树
			// [0,mid)
			int LeftNumInorderBegin = inorderBegin;
			int LeftNumInorderEnd = mid;
			// [mid+1,end)
			int RightNumInorderBegin = mid + 1;
			int RightNumInorderEnd = inorderEnd;

			// 切割前序遍历左右子树
			// [1,LeftNumInorderEnd-LeftNumInorderBegin)
			int LeftNumPreorderBegin = preorderBegin + 1;
			int LeftNumPreorderEnd = LeftNumPreorderBegin + LeftNumInorderEnd - LeftNumInorderBegin;
			// [LeftNumInorderEnd-LeftNumInorderBegin,end)
			int RightNumPreorderBegin = LeftNumPreorderBegin + LeftNumInorderEnd - LeftNumInorderBegin;
			int RightNumPreorderEnd = preorderEnd;

			// 递归
			root->left = traversal(inorder, LeftNumInorderBegin, LeftNumInorderEnd, preorder, LeftNumPreorderBegin,
			                       LeftNumPreorderEnd);
			root->right = traversal(inorder, RightNumInorderBegin, RightNumInorderEnd, preorder, RightNumPreorderBegin,
			                        RightNumPreorderEnd);
			return root;
		}
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			if (!preorder.size() || !inorder.size())
				return nullptr;
			return traversal(inorder, 0, inorder.size(), preorder, 0, inorder.size());
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