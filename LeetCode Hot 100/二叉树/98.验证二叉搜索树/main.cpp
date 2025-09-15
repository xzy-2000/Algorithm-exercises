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
		vector<int> vec;
		// �������
		void traversal(TreeNode *root) {
			// ��ֹ����
			if (root == nullptr) {
				return;
			}
			// ��
			traversal(root->left);
			// ��
			if (root != nullptr) {
				vec.push_back(root->val);
			}
			// ��
			traversal(root->right);
		}
	public:
		bool isValidBST(TreeNode *root) {
			traversal(root);
			for (int i = 1; i < vec.size(); i++) {
				if (vec[i - 1] >= vec[i])
					return false;
			}
			return true;
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
	//       4
	//      / \
	//     2   5
	//    / \
	//   1   3

	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	Solution solution;
	cout << solution.isValidBST(root) << endl;
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
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}