#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestPalindromeSubseq(string s) {
			// ����dp���麬��ͳ�ʼ��
			// dp[i][j]����ʾ���䷶Χ[i,j] ��ע��������ұգ����Ӵ�����
			vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
			// ��ʼ��
			for (int j = 0; j < s.size(); j++) {
				dp[j][j] = 1;
			}
			// ����
			for (int i = s.size() - 1; i >= 0; i--) {
				for (int j = i + 1; j < s.size(); j++) {
					if (s[i] == s[j]) {
						dp[i][j] = dp[i + 1][j - 1] + 2;
					} else {
						dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
					}
//					cout << "s[" << i << "] = " << s[i] << " s[" << j << "] = " << s[j];
//					cout << " dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
				}
			}
			return dp[0][s.size() - 1];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "bbbab"; // bbbb 4
	std::cout << solution.longestPalindromeSubseq(s);
	return 0;
}
/*
ʾ�� 1��

���룺s = "bbbab"
�����4
���ͣ�һ�����ܵ������������Ϊ "bbbb" ��
ʾ�� 2��

���룺s = "cbbd"
�����2
���ͣ�һ�����ܵ������������Ϊ "bb" ��
*/