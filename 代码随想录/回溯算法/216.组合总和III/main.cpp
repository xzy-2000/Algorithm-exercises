#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(int k, int n, int sum, int startIndex) {

			if (sum > n) { // ��֦����
				return;
			}
			// ��ֹ����
			if (path.size() == k) {
				if (sum == n)
					result.push_back(path);
				return;
			}
			// ����
			for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { //��֦
				// �ݹ�
				sum += i;
				path.push_back(i);
				backtracking(k, n, sum, i + 1);
				// ����
				sum -= i;
				path.pop_back();
			}

		}
	public:
		vector<vector<int>> combinationSum3(int k, int n) {
			backtracking(k, n, 0, 1);
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 9;
	int k = 3;
	vector<vector<int>> result = solution.combinationSum3(k, n);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
