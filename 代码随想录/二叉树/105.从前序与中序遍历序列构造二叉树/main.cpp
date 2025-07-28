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
			// �ҵ����ڵ�λ�ã��������ڵ㲢д����ֵ
			int rootValue = preorder[preorderBegin];
			TreeNode *root = new TreeNode(rootValue);
			// Ҷ�ӽڵ㣬ֱ�ӷ���
			if (preorderEnd - preorderBegin == 1)
				return root;
			// �ҵ����ڵ��λ��
			int mid;
			for (int i = inorderBegin; i < inorderEnd; i++) {
				if (inorder[i] == rootValue) {
					mid = i;
					break;
				}
			}
			// �и����������������
			// [0,mid)
			int LeftNumInorderBegin = inorderBegin;
			int LeftNumInorderEnd = mid;
			// [mid+1,end)
			int RightNumInorderBegin = mid + 1;
			int RightNumInorderEnd = inorderEnd;

			// �и�ǰ�������������
			// [1,LeftNumInorderEnd-LeftNumInorderBegin)
			int LeftNumPreorderBegin = preorderBegin + 1;
			int LeftNumPreorderEnd = LeftNumPreorderBegin + LeftNumInorderEnd - LeftNumInorderBegin;
			// [LeftNumInorderEnd-LeftNumInorderBegin,end)
			int RightNumPreorderBegin = LeftNumPreorderBegin + LeftNumInorderEnd - LeftNumInorderBegin;
			int RightNumPreorderEnd = preorderEnd;

			// �ݹ�
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
				cout << endl;  // ÿһ�㻻�У���ѡ��
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