#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int>> &matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			int flag_col0 = false, flag_row0 = false;
			for (int i = 0; i < m; i++) {
				if (matrix[i][0] == 0) {
					flag_col0 = true;
				}
			}
			for (int j = 0; j < n; j++) {
				if (matrix[0][j] == 0) {
					flag_row0 = true;
				}
			}
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					if (matrix[i][j] == 0) {
						matrix[i][0] = matrix[0][j] = 0;
					}
				}
			}
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					if (matrix[i][0] == 0 || matrix[0][j] == 0) {
						matrix[i][j] = 0;
					}
				}
			}
			if (flag_col0) {
				for (int i = 0; i < m; i++) {
					matrix[i][0] = 0;
				}
			}
			if (flag_row0) {
				for (int j = 0; j < n; j++) {
					matrix[0][j] = 0;
				}
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<int>> matrix = {{0, 1, 1, 2, 0}, {3, 1, 1, 5, 2}, {1, 1, 3, 1, 5}};
	solution.setZeroes(matrix);
	for (const auto perms : matrix) {
		for (int num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}