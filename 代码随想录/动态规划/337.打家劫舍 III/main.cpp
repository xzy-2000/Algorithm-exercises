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
		int rob(TreeNode *root) {
			vector<int> result = robTree(root);
			return max(result[0], result[1]);
		}

		vector<int> robTree(TreeNode *cur) {
			if (cur == nullptr)
				return {0, 0};
			// ��
			vector<int> left = robTree(cur->left);
			// ��
			vector<int> right = robTree(cur->right);
			// ��
			// ͵cur����ô�Ͳ���͵���ҽڵ㡣
			int val1 = cur->val + left[0] + right[0];
			// ��͵cur����ô����͵Ҳ���Բ�͵���ҽڵ㣬��ȡ�ϴ�����
			int val2 = max(left[0], left[1]) + max(right[0], right[1]);
			return {val2, val1}; // ˳��Ҫ����
		}

		int rob1(TreeNode *root) {
			// ����
			if (root == nullptr)
				return 0;
			if (root->left == nullptr && root->right == nullptr) {
				return root->val;
			}
			// ͵���ڵ�
			int val1 = root->val;
			if (root->left)
				val1 += rob(root->left->left) + rob(root->left->right); // ����root->left���൱�ڲ�����������
			if (root->right)
				val1 += rob(root->right->left) + rob(root->right->right);

			// ��͵���ڵ�
			int val2 = rob(root->left) + rob(root->right);
			return max(val1, val2);
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

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	/*
		    3
		   / \
		  2   3
	       \   \
	        3   1
	*/
	cout << solution.rob(root) << endl;
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}