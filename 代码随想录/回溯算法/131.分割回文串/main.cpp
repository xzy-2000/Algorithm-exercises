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
		vector<string> path; // ���Ѿ����ĵ��Ӵ�
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
					// substr�������Դ�һ���ַ����л�ȡ�Ӵ�,����һ��string,����s�д�pos��ʼ��n���ַ��Ŀ���(pos��Ĭ��ֵ��0)
					// n��Ĭ��ֵ��s.size()-pos,�����Ӳ�����Ĭ�Ͽ�������s),������Ϊһ�ֹ���string�ķ�����
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

	for (const auto &perm : result) {         // perm ��ÿһ�����У������� vector<int>
		for (auto num : perm) {                // num �������е�һ������
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}