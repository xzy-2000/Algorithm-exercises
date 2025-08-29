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
		// ǰ�����
		void preTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			vec.push_back(cur->val);    // ��
			preTraversal(cur->left, vec);  // ��
			preTraversal(cur->right, vec); // ��
		}

		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> result;
			preTraversal(root, result);
			return result;
		}

		// �������
		void inTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			inTraversal(cur->left, vec);  // ��
			vec.push_back(cur->val);    // ��
			inTraversal(cur->right, vec); // ��
		}

		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			inTraversal(root, result);
			return result;
		}

		// �������
		void postTraversal(TreeNode *cur, vector<int> &vec) {
			if (cur == NULL)
				return;
			postTraversal(cur->left, vec);  // ��
			postTraversal(cur->right, vec); // ��
			vec.push_back(cur->val);    // ��
		}

		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> result;
			postTraversal(root, result);
			return result;
		}
};



int main() {
	// ���������õĶ�����
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	Solution solution;

	// ǰ�����
	vector<int> preResult = solution.preorderTraversal(root);
	cout << "ǰ��������: ";
	for (int num : preResult)
		cout << num << " ";
	cout << endl;

	// �������
	vector<int> inResult = solution.inorderTraversal(root);
	cout << "����������: ";
	for (int num : inResult)
		cout << num << " ";
	cout << endl;

	// �������
	vector<int> postResult = solution.postorderTraversal(root);
	cout << "����������: ";
	for (int num : postResult)
		cout << num << " ";
	cout << endl;

	// �ͷ��ڴ�
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}