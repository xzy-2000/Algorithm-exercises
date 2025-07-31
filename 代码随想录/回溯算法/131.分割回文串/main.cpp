#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> partition(string s) {
			backtracing(s, 0);
			return result;
		}
	private:
		vector<vector<string>> result;
		vector<string> path; // 放已经回文的子串
		void backtracing(string s, int startIndex) {
			if (startIndex >= s.size()) {
				result.push_back(path);
			}
			for (int i = startIndex; i < s.size(); i++) {
				string str = s.substr(startIndex, i - startIndex + 1);
//				cout << "startIndex = " << startIndex << " i = " << i << " str = " << str;
				if (isPalindrome(s, startIndex, i)) {
//					cout << " is a palindrome + push" << endl;
//					string str = s.substr(startIndex, i - startIndex + 1);
					// substr函数可以从一个字符串中获取子串,返回一个string,包含s中从pos开始的n个字符的拷贝(pos的默认值是0)
					// n的默认值是s.size()-pos,即不加参数会默认拷贝整个s),可以作为一种构造string的方法。
					path.push_back(str);
				} else {
//					cout << " is not a palindrome" << endl;
					continue;
				}
				backtracing(s, i + 1);
				path.pop_back();
			}
		}
		bool isPalindrome(string s, int begin, int end) {
			for (int i = begin, j = end; i <= end && i <= j; i++, j--) {
				if (s[i] != s[j])
					return false;
			}
			return true;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "aab";
	vector<vector<string>> result = solution.partition(s);

	for (const auto &perm : result) {         // perm 是每一个排列，类型是 vector<int>
		for (auto num : perm) {                // num 是排列中的一个数字
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}