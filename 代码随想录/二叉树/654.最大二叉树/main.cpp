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
		TreeNode *traversal(vector<int> &nums) {
			TreeNode *root = new TreeNode(0);
			if (nums.size() == 1) {
				root->val = nums.front();
				return root;
			}

			// 找出最大值
			int MaxIndex = 0;
			int maxValueIndex = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (maxValueIndex < nums[i]) {
					MaxIndex = i;
					maxValueIndex = nums[i];
				}
			}
			root->val = maxValueIndex;
			if (MaxIndex > 0) {
				// 切割左子树[begin,MaxIndex)
				vector<int> numsLeft(nums.begin(), nums.begin() + MaxIndex);
				// 左子树
				root->left = traversal(numsLeft);
			}
			if (MaxIndex < (nums.size() - 1)) {
				// 切割右子树[MaxIndex+1,end)
				vector<int> numsRight(nums.begin() + MaxIndex + 1, nums.end());
				// 右子树
				root->right = traversal(numsRight);
			}
			return root;
		}
		TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
			return traversal(nums);
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

	vector<int> nums = {3, 2, 1, 6, 0, 5};
	/*
		   6
		 /   \
		3     5
		 \   /
		  2 0
		   \
		    1
	*/
	TreeNode *root = solution.constructMaximumBinaryTree(nums);
	cout << "Level order traversal:" << endl;
	solution.levelOrder(root);
	return 0;
}