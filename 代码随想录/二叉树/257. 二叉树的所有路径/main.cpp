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
		void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
			//ǰ�����
			path.push_back(cur->val);//�У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path��
			// ��ŵ���Ҷ�ӽڵ�
			if (cur->left == nullptr && cur->right == nullptr) { //�ߵ���Ҷ�ӽڵ㣬��ʼ��¼
				string sPath;
				for (int i = 0; i < path.size() - 1; i++) {
					sPath += to_string(path[i]);
					sPath += "->";
				}
				sPath += to_string(path[path.size() - 1]);
				result.push_back(sPath);
				return;
			}
			if (cur->left != nullptr) { // ��
				traversal(cur->left, path, result);
				path.pop_back();// ����
			}
			if (cur->right != nullptr) { // ��
				traversal(cur->right, path, result);
				path.pop_back();// ����
			}
		}
		vector<string> binaryTreePaths(TreeNode *root) {
			vector<string> result;
			vector<int> path;			//path�������洢ÿһ��·���Ľڵ�
			if (root == NULL)
				return result;
			// �����ڵݹ�ĺ����ж���path����Ϊÿһ�εݹ鶼�����¶���һ������
			traversal(root, path, result);
			return result;
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
	//    / \
	//   3   4
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
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

	vector<string> paths = solution.binaryTreePaths(root);

	for (const auto &path : paths) {
		for (auto str : path) {
			cout << str;
		}
		cout << endl;
	}

//	for (int i = 0; i < paths.size(); i++) {
//		cout << paths[i] << endl;
//
//	}
	// �ͷ��ڴ�
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}