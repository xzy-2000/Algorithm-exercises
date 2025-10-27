#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool searchMatrix(vector<vector<int>> &matrix, int target) {
			int m = matrix.size(), n = matrix[0].size();
			int i = 0, j = n - 1;
			while (i < m && j >= 0) {
				if (matrix[i][j] == target) {
					return true;
				} else if (matrix[i][j] < target) {
					i++;
				} else {
					j--;
				}
			}
			return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<int>> matrix = {{0, 1, 1, 2, 0}, {3, 1, 1, 5, 2}, {1, 1, 3, 1, 5}};
	int target = 3;
	cout << solution.searchMatrix(matrix, target);

	return 0;
}