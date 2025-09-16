#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};


class Solution {
	public:
		// ��������
		TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
			// ��ֹ����
			if (root == nullptr || root == p || root == q) {
				return root;
			}
			// ��
			TreeNode *left = lowestCommonAncestor(root->left, p, q);
			// ��
			TreeNode *right = lowestCommonAncestor(root->right, p, q);
			// ��
			if (left != nullptr && right != nullptr)
				return root;
			// ������Ϊ�գ���������Ϊ��
			if (left == nullptr && right != nullptr)
				return right;
			// ��������Ϊ�գ�������Ϊ��
			else if (left != nullptr && right == nullptr)
				return left;
			else
				return nullptr;
		}


		// �������
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
	// ���������õĶ�����
	//        3
	//      /   \
	//     5     1
	//    / \   / \
	//   6   2 0   8
	//      / \
	//     7   4

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	Solution solution;

	TreeNode *p = root->left->left;
	TreeNode *q = root->left->right->right;
	TreeNode *CommonAncestor = solution.lowestCommonAncestor(root, p, q);
	cout << "lowestCommonAncestor = " << CommonAncestor->val << endl;
	// �������
	vector<vector<int>> result = solution.levelOrder(root);

	// �������������
	cout << "����������:" << endl;
	for (const auto &level : result) {
		cout << "�� " << &level - &result[0] + 1 << " ��: ";
		for (int num : level) {
			cout << num << " ";
		}
		cout << endl;
	}

	// �ͷ��ڴ�
	delete root->left->right->right;
	delete root->left->right->left;
	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}