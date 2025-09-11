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
			// ѡ���м�λ����ߵ�������Ϊ���ڵ㣬�������
			int mid = (left + right) >> 1;
			TreeNode *root = new TreeNode(nums[mid]);
			// ��
			root->left = backtracing(nums, left, mid - 1);
			// ��
			root->right = backtracing(nums, mid + 1, right);
			return root;
		}
	public:
		TreeNode *sortedArrayToBST(vector<int> &nums) {
			return backtracing(nums, 0, nums.size() - 1);
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
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	vector<int> nums = {-10, -3, 0, 5, 9};

	Solution solution;
	TreeNode *root = solution.sortedArrayToBST(nums);
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
	return 0;
}