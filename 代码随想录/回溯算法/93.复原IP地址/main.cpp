#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<string> result;
		int pointNum = 0;
		void backtracking(string &s, int startIndex) {
			// 中止条件
			if (pointNum == 3) { // 逗点数量为3时，分隔结束
				// 判断第四段子字符串是否合法，如果合法就放进result中
				if (isIP(s, startIndex, s.size() - 1)) {
//					cout << "push_back" << s << endl;
					result.push_back(s);
				}
				return;
			}
			// 遍历
			for (int i = startIndex; i < s.size(); i++) {
				if (isIP(s, startIndex, i)) {
					s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
//					cout << "insert " << s.substr(startIndex, i + 1 - startIndex) << endl;
					pointNum++;
					backtracking(s, i + 2);
					s.erase(s.begin() + i + 1);
//					cout << "erase " << s.substr(startIndex, i + 1 - startIndex) << endl;
					pointNum--;
				} else {
					break;
				}
			}
		}
		bool isIP(string &s, int start, int end) {
			// 头不能大于尾
			if (end < start || end - start >= 3)
				return false;
			// 0开头的数字不合法
			if (s[start] == '0' && start != end)
				return false;
			int num = 0;
			for (int i = start; i <= end; i++) {
				if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
					return false;
				}
				num = 10 * num + (s[i] - '0');
			}
			// cout << "start = " << start << " end = " << end << " num = " << num << endl;
			if (num > 255) { // 如果大于255了不合法
				return false;
			}
			return true;
		}
	public:
		vector<string> restoreIpAddresses(string s) {
			backtracking(s, 0);
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "25525511135";
	vector<string> result = solution.restoreIpAddresses(s);
	cout << "all ip display" << endl;

	for (const auto str : result) {          // perm 是每一个排列，类型是 vector<int>
		cout << str << endl;;
	}

	return 0;
}