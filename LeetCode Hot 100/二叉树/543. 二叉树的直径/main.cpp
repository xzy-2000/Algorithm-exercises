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
		int ans;
		int depth(TreeNode *root) {
			// ��ֹ����
			if (root == nullptr) {
				return 0;
			}
			// �ݹ�
			int L = depth(root->left); 	// �����Ϊ�������������
			int R = depth(root->right); // �Ҷ���Ϊ�������������
			//ά��ÿ������ֱ�������ֵ�������
			//��ÿ���ڵ�:��������������ұ����֮�ʹ��ڵ�ǰ���ֵ
			//�������ֵ������
			ans = max(ans, R + L + 1);
			//���ظ�����һ�����ȣ�����
			//�ײ�->�м��->�ϲ�->���ϲ�
			return max(L, R) + 1;
		}
	public:
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
		// ��������ֱ��
		// ĳһ����������������������֮�� + 1������ = ��������ֱ��
		int diameterOfBinaryTree(TreeNode *root) {
			ans = 1;//�ڵ����
			depth(root);
			return ans - 1;//������-1=ֱ��
		}
//		int diameterOfBinaryTree(TreeNode *root) {
//
//			int result = 0;
//			auto dfs = []()->int{
//
//			};
//		}
};




int main() {
	// ���������õĶ�����
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	//      /
	//     6
	//      \	
	//		 7
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->left = new TreeNode(6);
	root->left->right->left->right = new TreeNode(7);

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
	cout << solution.diameterOfBinaryTree(root);
	// �ͷ��ڴ�
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}