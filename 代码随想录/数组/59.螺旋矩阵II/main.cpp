#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> matrix(n, vector<int>(n, 0)); // ʹ��vector����һ��n*n��ά����
			int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
			int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
			int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
			int count = 1; // ������������ÿһ���ո�ֵ
			int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
			int i, j;
			while (loop--) {
				i = startx;
				j = starty;
				// �Ϸ�������
				for (j; j < n - offset; j++)
					matrix[i][j] = count++;
				// �ҷ����ϵ���
				for (i; i < n - offset; i++)
					matrix[i][j] = count++;
				// �·����ҵ���
				for (j; j > starty; j--)
					matrix[i][j] = count++;
				// �󷽴��ϵ���
				for (i; i > startx; i--)
					matrix[i][j] = count++;

				// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
				startx++;
				starty++;

				// offset ����ÿһȦ��ÿһ���߱����ĳ���
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