#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};


class Solution {
	private:
		vector<int> nums;
	public:
		// �������
		void backthroughting(TreeNode *root) {
			// ��ֹ����
			if (root == nullptr) {
				return;
			}
			// ��
			backthroughting(root->left);
			// ��
			nums.emplace_back(root->val);
			// ��
			backthroughting(root->right);
		}
		// ����������
		int kthSmallest(TreeNode *root, int k) {
			backthroughting(root);
			return nums[k - 1];
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
	//       5
	//      / \
	//     2   6
	//    / \
	//   1   4
	//      /
	//     3
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);

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

	int k = 3;
	cout << solution.kthSmallest(root, 3);
	// �ͷ��ڴ�
	delete root->left->right->left;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}