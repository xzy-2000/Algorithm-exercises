#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			int Index = 0;
			if (digits.size() == 0) {
				return result;
			}
			backtracking(digits, Index);
			return result;
		}
	private:
		const string letterMap[10] = {
			"", // 0
			"", // 1
			"abc", // 2
			"def", // 3
			"ghi", // 4
			"jkl", // 5
			"mno", // 6
			"pqrs", // 7
			"tuv", // 8
			"wxyz", // 9
		};
		vector<string> result;
		string path;
		void backtracking(string digits, int index) {
			// ��ֹ����
			if (path.size() == digits.size()) {
				result.push_back(path);
				return;
			}
			int digit = digits[index] - '0'; 		// ��ָ�������
			string letters = letterMap[digit];
			// ����
			for (int i = 0; i < letters.size(); i++) {
				path.push_back(letters[i]);				// ����
				backtracking(digits, index + 1);	// �ݹ�
				path.pop_back();				// ����
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;
	string digits = "23";
	vector<string> result = solution.letterCombinations(digits);

	for (int i = 0; i < result.size(); i++) {

		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}