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
		int maxDepth(TreeNode *root) {
			if (root == nullptr)
				return 0;
//			int leftdepth = maxDepth(root->left);       // ��
//			int rightdepth = maxDepth(root->right);     // ��
//			int depth = 1 + max(leftdepth, rightdepth); // ��
//			return depth;
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
	// ���������õĶ�����
	//       1
	//      / \
	//     2   2
	//    /
	//   3
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(4);
	Solution solution;
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
	cout << solution.maxDepth(root);
	// �ͷ��ڴ�
	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}