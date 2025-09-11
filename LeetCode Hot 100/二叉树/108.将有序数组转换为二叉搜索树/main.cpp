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
	private:
		TreeNode *backtracing(vector<int> &nums, int left, int right) {
			if (left > right) {
				return nullptr;
			}
			// 选择中间位置左边的数字作为根节点，中序遍历
			int mid = (left + right) >> 1;
			TreeNode *root = new TreeNode(nums[mid]);
			// 左
			root->left = backtracing(nums, left, mid - 1);
			// 右
			root->right = backtracing(nums, mid + 1, right);
			return root;
		}
	public:
		TreeNode *sortedArrayToBST(vector<int> &nums) {
			return backtracing(nums, 0, nums.size() - 1);
		}
		// 层序遍历
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
	// 构建测试用的二叉树
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	vector<int> nums = {-10, -3, 0, 5, 9};

	Solution solution;
	TreeNode *root = solution.sortedArrayToBST(nums);
	// 层序遍历
	vector<vector<int>> result = solution.levelOrder(root);

	// 输出层序遍历结果
	cout << "层序遍历结果:" << endl;
	for (const auto &level : result) {
		cout << "第 " << &level - &result[0] + 1 << " 层: ";
		for (int num : level) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}