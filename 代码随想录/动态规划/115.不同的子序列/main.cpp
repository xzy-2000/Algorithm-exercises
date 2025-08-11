#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int numDistinct(string s, string t) {
			// ����dp���麬��ͳ�ʼ��
			// dp[i][j]ָ����s��0��i-1��t��0��j-1ʱ�м���ƥ����
			vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
			// ��ʼ��
			// dp[i][0] ��ʾ����i-1Ϊ��β��s�������ɾ��Ԫ�أ����ֿ��ַ����ĸ�����
			for (int i = 0; i < s.size(); i++) {
				dp[i][0] = 1;
			}
			// dp[0][j]�����ַ���s�������ɾ��Ԫ�أ�������j-1Ϊ��β���ַ���t�ĸ�����
			for (int j = 1; j < t.size(); j++) {
				dp[0][j] = 0;
			}
			// ����
			for (int i = 1; i <= s.size(); i++) {
				for (int j = 1; j <= t.size(); j++) {
					if (s[i - 1] == t[j - 1])
						dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j];
//					cout << dp[i][j] << " ";
				}
//				cout << endl;
			}
			return dp[s.size()][t.size()];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "baegg";
	string t = "bag";
	std::cout << solution.numDistinct(s, t);
	return 0;
}