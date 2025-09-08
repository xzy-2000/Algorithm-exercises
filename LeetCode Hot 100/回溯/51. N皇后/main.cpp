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
		// row �����У�col ������
		void backtracing(int n, int row, vector<string> &chessboard) {
			// ��ֹ����,8�ж�������
			if (row == n) {
				result.push_back(chessboard);
				return;
			}
			// ����,i�����i��
			for (int col = 0; col < n; col++) {
				if (isValid(n, row, col, chessboard)) {
					chessboard[row][col] = 'Q';
					// �ݹ�
					backtracing(n, row + 1, chessboard);
					// ����
					chessboard[row][col] = '.';
				}
			}
		}
		// row �����У�col ������
		bool isValid(int n, int row, int col, vector<string> &chessboard) {
			// �����
			for (int i = 0; i < row; i++) {
				if (chessboard[i][col] == 'Q') {
					return false;
				}
			}
			// ��� 45�Ƚ��Ƿ��лʺ�
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
				if (chessboard[i][j] == 'Q') {
					return false;
				}
			}
			// ��� 135�Ƚ��Ƿ��лʺ�
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