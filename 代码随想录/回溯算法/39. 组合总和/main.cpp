#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		int sum;
		void backtracking(int sum, int startIndex, int target, vector<int> &candidates) {
			// ��ֹ����
			if (sum > target) {
				return;
			}
			if (sum == target) {
//				cout << "get!";
				result.push_back(path);
				return;
			}
			// ����
			for (int i = startIndex; i < candidates.size(); i++) {
				sum += candidates[i];
//				cout << "sum = " << sum << endl;
				path.push_back(candidates[i]);
				// �ݹ�
				backtracking(sum, i, target, candidates);// �ؼ���:����i+1�ˣ���ʾ�����ظ���ȡ��ǰ����
				// ����

				sum -= candidates[i];
//				cout << "sum = " << sum << endl;
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
			backtracking(0, 0, target, candidates);
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> candidates = {2, 3, 5};
	int target = 8;
	vector<vector<int>> result = solution.combinationSum(candidates, target);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
