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
		TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {

			// ��һ�����Ƿ�Ϊ����
			if (postorder.size() == 0)
				return nullptr;
			// �ڶ�������������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
			int rootValue = postorder[postorder.size() - 1];
			TreeNode *root = new TreeNode(rootValue);

			// Ҷ�ӽڵ�
			if (postorder.size() == 1)
				return root;

			// �����������и�㣬�и������������
			int delimiterIndex;
			for (int i = 0; i < inorder.size(); i++) {
				if (inorder[i] == rootValue) {
					delimiterIndex = i;
					break;
				}
			}
			// ���Ĳ����и��������飬�õ� ��������������������� �๹��

			// ����ҿ����䣺[0, delimiterIndex)
			vector<int> inorder_left(inorder.begin(), inorder.begin() + delimiterIndex);
			// [delimiterIndex + 1, end)
			vector<int> inorder_right(inorder.begin() + delimiterIndex + 1, inorder.end());

			// postorder ����ĩβԪ��
			// postorder.resize(postorder.size() - 1);
			postorder.pop_back();

			// ���岽���и�������飬�õ� ����������ͺ���������
			// ����ҿ���ע������ʹ���������������С��Ϊ�и�㣺[0, leftInorder.size)
			vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
			// [leftInorder.size(), end)
			vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end());

			// ������
			root->left = traversal(inorder_left, postorder_left);
			root->right = traversal(inorder_right, postorder_right);

			return root;
		}

		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			if (inorder.size() == 0 || postorder.size() == 0)
				return nullptr;
			return traversal(inorder, postorder);
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

	vector<int> inorder = {9, 3, 15, 20, 7};
	vector<int> postorder = {9, 15, 7, 20, 3};
	/*
		  3
		 / \
		9  20
		  /  \
		 15   7
	*/
	TreeNode *root = solution.buildTree(inorder, postorder);
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}