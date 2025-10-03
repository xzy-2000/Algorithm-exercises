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
//		unordered_map<long long, int> preSumCount;  // 记录当前路径上出现的前缀和以及数量
//		int dfs(TreeNode *root, long long preSum, int targetSum) {
//			// 终止条件
//			if (root == nullptr) {
//				return 0;
//			}
//			preSum += root->val;        // 更新节点和
//
//			int pathCnt = 0;
//			if (preSumCount.count(preSum - targetSum)) {
//				pathCnt = preSumCount[preSum - targetSum];	// 从哈希表中获取能和preSum配对的前缀和个数
//			}
//			preSumCount[preSum]++;   // 将当前前缀和加入哈希表
//			if (root != nullptr) {
//				pathCnt += dfs(root->left, preSum, targetSum); // 左
//				pathCnt += dfs(root->right, preSum, targetSum);// 右
//			}
//			preSumCount[preSum] -= 1;   // 这个节点所在的路径都处理完了，这个前缀和也就没用了
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
			// 终止条件
			if (root == nullptr) {
				return 0;
			}
			cur += root->val;
			int count = 0;
			if (cur == targetSum) {
				count++;
			}
			if (root != nullptr) {
				count += dfs(root->left, cur, targetSum); // 左
				count += dfs(root->right, cur, targetSum); // 右
			}
			return count;
		}
//		int pathSum(TreeNode *root, int targetSum) {
//			preSumCount[0] = 1;                 // 有一个默认的前缀和0
//			return dfs(root, 0, targetSum);
//		}

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

	int targetSum = 8;
	cout << solution.pathSum(root, targetSum);
	return 0;
}