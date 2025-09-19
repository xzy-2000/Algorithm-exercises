#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			string str;
			backtracing(str, n, 0, 0);
			return result;
		}

	private:
		vector<string> result;
		void backtracing(string &str, int n, int left, int right) {
			// ÖÕÖ¹Ìõ¼ş
			if (str.size() == n * 2) {
				result.emplace_back(str);
				return;
			}
			// ±éÀú
			if (left < n) {
				str.push_back('(');
				backtracing(str, n, left + 1, right);
				str.pop_back();
			}
			if (right < left) {
				str.push_back(')');
				backtracing(str, n, left, right + 1);
				str.pop_back();
			}
		}

};

int main(int argc, char **argv) {
	Solution solution;
	int n = 3;
	vector<string> result = solution.generateParenthesis(n);

	for (const auto &s : result) {
		cout << s << " ";
	}
}