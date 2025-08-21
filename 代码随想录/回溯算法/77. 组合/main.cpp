#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {

			backtracking(n, k, 1);
			return result;
		}
	private:
		vector<vector<int>> result; // ��ŷ�����������ļ���
		vector<int> path; // ������ŷ����������
		void backtracking(int n, int k, int startIndex) {
			// ��ֹ����
			if (path.size() == k) {
				result.push_back(path);
				return;
			}
			//�ݹ�����ڵ�
			for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
				// ����ڵ�;
				path.push_back(i);
				// �ݹ�
				backtracking(n, k, i + 1);
				//���ݣ�����������
				path.pop_back();
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 4;
	int k = 2;
	vector<vector<int>> result = solution.combine(n, k);

//	cout << result.size() << endl;
//	cout << result[1].size() << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}