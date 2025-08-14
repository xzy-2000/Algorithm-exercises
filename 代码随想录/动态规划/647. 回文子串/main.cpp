#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countSubstrings(string s) {
			// ����dp���麬��ͳ�ʼ��
			// �������͵�dp[i][j]����ʾ���䷶Χ[i,j] ��ע��������ұգ����Ӵ��Ƿ��ǻ����Ӵ���
			// �����dp[i][j]Ϊtrue������Ϊfalse��
			vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
			int cnt = 0;
			// ��ʼ��
			// dp[i][i] ��ʾ����s[i]�Ƿ�Ϊ���Ĵ����϶��ǣ���Ϊֻ��һ���ַ�
//			for (int i = 0; i < s.size(); i++) {
//				dp[i][i] = 1;
//			}
			// ����
			for (int i = s.size() - 1; i >= 0; i--) {
				for (int j = i; j < s.size(); j++) {
					if (s[i] == s[j]) {
						if (i + 1 == j || i == j) { // ��ʱ��s[i]��s[j]����1 λ������ͬ1 λ
							dp[i][j] = true;
							cnt++;
						} else if (dp[i + 1][j - 1] == true) { // j ����i����[i + 1,j - 1]�Ѿ��ǻ��Ĵ���
							dp[i][j] = true;
							cnt++;
						}
						// cout << "s[i] = " << s[i] << " s[j] = " << s[j] << " i = " << i << " j = " << j << " dp[i][j] = " << dp[i][j] << endl;
					}
				}
			}
			return cnt;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "aaa"; // a a b a aa aa aba aba
	std::cout << solution.countSubstrings(s);
	return 0;
}
/*
s[i] = a s[j] = a i = 2 j = 2
s[i] = a s[j] = a i = 1 j = 1
s[i] = a s[j] = a i = 1 j = 2
s[i] = a s[j] = a i = 0 j = 0
s[i] = a s[j] = a i = 0 j = 1
*/