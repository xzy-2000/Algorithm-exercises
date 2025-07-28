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

			// 第一步，是否为空树
			if (postorder.size() == 0)
				return nullptr;
			// 第二步：后序遍历数组最后一个元素，就是当前的中间节点
			int rootValue = postorder[postorder.size() - 1];
			TreeNode *root = new TreeNode(rootValue);

			// 叶子节点
			if (postorder.size() == 1)
				return root;

			// 第三步：找切割点，切割中序遍历数组
			int delimiterIndex;
			for (int i = 0; i < inorder.size(); i++) {
				if (inorder[i] == rootValue) {
					delimiterIndex = i;
					break;
				}
			}
			// 第四步：切割中序数组，得到 中序左数组和中序右数组 类构造

			// 左闭右开区间：[0, delimiterIndex)
			vector<int> inorder_left(inorder.begin(), inorder.begin() + delimiterIndex);
			// [delimiterIndex + 1, end)
			vector<int> inorder_right(inorder.begin() + delimiterIndex + 1, inorder.end());

			// postorder 舍弃末尾元素
			// postorder.resize(postorder.size() - 1);
			postorder.pop_back();

			// 第五步：切割后序数组，得到 后序左数组和后序右数组
			// 左闭右开，注意这里使用了左中序数组大小作为切割点：[0, leftInorder.size)
			vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
			// [leftInorder.size(), end)
			vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end());

			// 第六步
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
				cout << endl;  // 每一层换行（可选）
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