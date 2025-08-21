#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {

			backtracking(n, k, 1);
			return result;
		}
	private:
		vector<vector<int>> result; // 存放符合条件结果的集合
		vector<int> path; // 用来存放符合条件结果
		void backtracking(int n, int k, int startIndex) {
			// 终止条件
			if (path.size() == k) {
				result.push_back(path);
				return;
			}
			//递归遍历节点
			for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
				// 处理节点;
				path.push_back(i);
				// 递归
				backtracking(n, k, i + 1);
				//回溯，撤销处理结果
				path.pop_back();
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 4;
	int k = 2;
	vector<vector<int>> result = solution.combine(n, k);

//	cout << result.size() << endl;
//	cout << result[1].size() << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}