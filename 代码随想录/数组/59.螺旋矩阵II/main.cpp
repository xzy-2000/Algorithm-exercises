#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> matrix(n, vector<int>(n, 0)); // 使用vector定义一个n*n二维数组
			int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
			int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
			int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
			int count = 1; // 用来给矩阵中每一个空格赋值
			int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
			int i, j;
			while (loop--) {
				i = startx;
				j = starty;
				// 上方从左到右
				for (j; j < n - offset; j++)
					matrix[i][j] = count++;
				// 右方从上到下
				for (i; i < n - offset; i++)
					matrix[i][j] = count++;
				// 下方从右到左
				for (j; j > starty; j--)
					matrix[i][j] = count++;
				// 左方从上到下
				for (i; i > startx; i--)
					matrix[i][j] = count++;

				// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
				startx++;
				starty++;

				// offset 控制每一圈里每一条边遍历的长度
				offset += 1;
			}
			if (n % 2)
				matrix[mid][mid] = count;
			return matrix;
		}
};


int main() {
	Solution solution;
	int n = 5;
	vector<vector<int>> matrix = solution.generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}