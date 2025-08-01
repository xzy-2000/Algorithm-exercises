#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<string> result;
		int pointNum = 0;
		void backtracking(string &s, int startIndex) {
			// ��ֹ����
			if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����
				// �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
				if (isIP(s, startIndex, s.size() - 1)) {
//					cout << "push_back" << s << endl;
					result.push_back(s);
				}
				return;
			}
			// ����
			for (int i = startIndex; i < s.size(); i++) {
				if (isIP(s, startIndex, i)) {
					s.insert(s.begin() + i + 1, '.'); // ��i�ĺ������һ������
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
			// ͷ���ܴ���β
			if (end < start || end - start >= 3)
				return false;
			// 0��ͷ�����ֲ��Ϸ�
			if (s[start] == '0' && start != end)
				return false;
			int num = 0;
			for (int i = start; i <= end; i++) {
				if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
					return false;
				}
				num = 10 * num + (s[i] - '0');
			}
			// cout << "start = " << start << " end = " << end << " num = " << num << endl;
			if (num > 255) { // �������255�˲��Ϸ�
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

	for (const auto str : result) {          // perm ��ÿһ�����У������� vector<int>
		cout << str << endl;;
	}

	return 0;
}