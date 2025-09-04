#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool searchMatrix(vector<vector<int>> &matrix, int target) {
			int m = matrix.size();	// ÐÐ
			int n = matrix[0].size();	// ÁÐ
			int left = 0, right = n * m - 1;
			while (left < right) {
				int mid = (left + right) >> 1;
				if (matrix[mid / n][mid % n] >= target) {
					right = mid;
				} else {
					left = mid + 1;
				}
			}
			if (matrix[right / n][right % n] == target)
				return true;
			return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int target = 3;

	vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	cout << solution.searchMatrix(matrix, target);
	return 0;
}