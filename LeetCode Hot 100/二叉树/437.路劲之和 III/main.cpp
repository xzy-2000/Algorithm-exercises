#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};


class Solution {
//	private:
//		unordered_map<long long, int> preSumCount;  // ��¼��ǰ·���ϳ��ֵ�ǰ׺���Լ�����
//		int dfs(TreeNode *root, long long preSum, int targetSum) {
//			// ��ֹ����
//			if (root == nullptr) {
//				return 0;
//			}
//			preSum += root->val;        // ���½ڵ��
//
//			int pathCnt = 0;
//			if (preSumCount.count(preSum - targetSum)) {
//				pathCnt = preSumCount[preSum - targetSum];	// �ӹ�ϣ���л�ȡ�ܺ�preSum��Ե�ǰ׺�͸���
//			}
//			preSumCount[preSum]++;   // ����ǰǰ׺�ͼ����ϣ��
//			if (root != nullptr) {
//				pathCnt += dfs(root->left, preSum, targetSum); // ��
//				pathCnt += dfs(root->right, preSum, targetSum);// ��
//			}
//			preSumCount[preSum] -= 1;   // ����ڵ����ڵ�·�����������ˣ����ǰ׺��Ҳ��û����
//			return pathCnt;
//		}
	public:
		int pathSum(TreeNode *root, int targetSum) {
			if (root == nullptr)
				return 0;
			queue<TreeNode *> que;
			que.push(root);
			int result = 0;
			while (!que.empty()) {
				TreeNode *node = que.front();
				que.pop();
				result += dfs(node, 0, targetSum);
				if (node != nullptr) {
					que.push(node->left);
					que.push(node->right);
				}
			}
			return result;
		}
		int dfs(TreeNode *root, long long cur, int targetSum) {
			// ��ֹ����
			if (root == nullptr) {
				return 0;
			}
			cur += root->val;
			int count = 0;
			if (cur == targetSum) {
				count++;
			}
			if (root != nullptr) {
				count += dfs(root->left, cur, targetSum); // ��
				count += dfs(root->right, cur, targetSum); // ��
			}
			return count;
		}
//		int pathSum(TreeNode *root, int targetSum) {
//			preSumCount[0] = 1;                 // ��һ��Ĭ�ϵ�ǰ׺��0
//			return dfs(root, 0, targetSum);
//		}

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
	//       10
	//      /  \
	//     5   -3
	//    / \    \
	//   3   2   11
	//  / \   \
	// 3  -2   1

	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);

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

	int targetSum = 8;
	cout << solution.pathSum(root, targetSum);
	return 0;
}