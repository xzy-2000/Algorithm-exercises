#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<string> chessboard(n, string(n, '.'));
			backtracing(n, 0, chessboard);
			return result;
		}
	private:
		vector<vector<string>> result;
		// row 代表行，col 代表列
		void backtracing(int n, int row, vector<string> &chessboard) {
			// 终止条件,8行都放满了
			if (row == n) {
				result.push_back(chessboard);
				return;
			}
			// 遍历,i代表第i行
			for (int col = 0; col < n; col++) {
				if (isValid(n, row, col, chessboard)) {
					chessboard[row][col] = 'Q';
					// 递归
					backtracing(n, row + 1, chessboard);
					// 回溯
					chessboard[row][col] = '.';
				}
			}
		}
		// row 代表行，col 代表列
		bool isValid(int n, int row, int col, vector<string> &chessboard) {
			// 检查列
			for (int i = 0; i < row; i++) {
				if (chessboard[i][col] == 'Q') {
					return false;
				}
			}
			// 检查 45度角是否有皇后
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
				if (chessboard[i][j] == 'Q') {
					return false;
				}
			}
			// 检查 135度角是否有皇后
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
				if (chessboard[i][j] == 'Q') {
					return false;
				}
			}
			return true;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 4;
	vector<vector<string>> result = solution.solveNQueens(n);

	for (const auto &perms : result) {
		for (auto num : perms) {
			cout << num << endl;
		}
		cout << endl;
	}
}