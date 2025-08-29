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
		// ǰ����� ��->��->��
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			if (root == NULL)
				return result;
			st.push(root);					//����Ҫ
			while (!st.empty()) {
				TreeNode *node = st.top(); //��
				st.pop();
				result.push_back(node->val);
				if (node->right != nullptr)
					st.push(node->right);    // �ң��սڵ㲻��ջ��
				if (node->left != nullptr)
					st.push(node->left);     // �󣨿սڵ㲻��ջ��
			}
			return result;
		}

		// �������
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			TreeNode *cur = root;
			while (cur != NULL || !st.empty()) {
				if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
					st.push(cur); // �����ʵĽڵ�Ž�ջ
					cur = cur->left;                // ��
				} else {
					cur = st.top();
					st.pop();
					result.push_back(cur->val);	// ��
					cur = cur->right;				// ��

				}
			}
			return result;
		}

		// �������  ��->��->��
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> result;
			stack<TreeNode *> st;
			if (root == NULL)
				return result;
			st.push(root);					//����Ҫ
			while (!st.empty()) {
				TreeNode *node = st.top(); //��
				st.pop();
				result.push_back(node->val);
				if (node->left != nullptr)
					st.push(node->left);     // �󣨿սڵ㲻��ջ��
				if (node->right != nullptr)
					st.push(node->right);    // �ң��սڵ㲻��ջ��
			}
			reverse(result.begin(), result.end());
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