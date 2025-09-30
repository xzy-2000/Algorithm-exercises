#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void rotate(vector<vector<int>> &matrix) {
			int n = matrix.size();
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					swap(matrix[i][j], matrix[j][i]);
				}
			}
			for (int i = 0; i < n; i++) {
				reverse(matrix[i].begin(), matrix[i].end());
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<int>> matrix = {{0, 1, 1}, {3, 1, 1}, {1, 1, 3}};

	for (const auto perms : matrix) {
		for (int num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
	cout << endl;
	solution.rotate(matrix);
	for (const auto perms : matrix) {
		for (int num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}