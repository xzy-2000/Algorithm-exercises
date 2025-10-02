#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	public:
		vector<int> spiralOrder(vector<vector<int>> &matrix) {
			int n = matrix.size();
			int m = matrix[0].size();
			int size = n * m;
			vector<int> res(size);
			int i = 0, j = 0, di = 0;
			for (int k = 0; k < m * n; k++) { // 一共走 mn 步
				res[k] = matrix[i][j];
				matrix[i][j] = INT_MAX;
				int x = i + dx[di];
				int y = j + dy[di];
				if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] == INT_MAX) {
					di = (di + 1) % 4;
				}
				i += dx[di];
				j += dy[di];
			}
			return res;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	for (const auto perms : matrix) {
		for (int num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<int> res = solution.spiralOrder(matrix);
	for (const auto num : res) {
		cout << num << " ";
	}
	return 0;
}