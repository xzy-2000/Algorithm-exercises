#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minDistance(string word1, string word2) {
			// ����dp���麬��ͳ�ʼ��
			// dp[i][j]����i-1Ϊ��β���ַ���word1������j-1λ��β���ַ���word2��
			// ��Ҫ�ﵽ��ȣ�����Ҫɾ��Ԫ�ص����ٴ�����
			vector<vector<uint64_t>> dp(word1.size() + 1, vector<uint64_t>(word2.size() + 1, 0));
			// ��ʼ��
			// dp[i][0] ��ʾ����i-1Ϊ��β��s�������ɾ��Ԫ�أ����ֿ��ַ����ĸ�����
			for (int i = 0; i <= word1.size(); i++) {
				dp[i][0] = i;
			}
			// dp[0][j]�����ַ���s�������ɾ��Ԫ�أ�������j-1Ϊ��β���ַ���t�ĸ�����
			for (int j = 1; j <= word2.size(); j++) {
				dp[0][j] = j;
			}
			// ����
			for (int i = 1; i <= word1.size(); i++) {
				for (int j = 1; j <= word2.size(); j++) {
					if (word1[i - 1] == word2[j - 1])
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
//					cout << dp[i][j] << " ";
				}
//				cout << endl;
			}
			return dp[word1.size()][word2.size()];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string word1 = "intention";
	string word2 = "execution";
	std::cout << solution.minDistance(word1, word2);
	return 0;
}
/*
���룺word1 = "intention", word2 = "execution"

�����5

���ͣ�  intention -> inention (ɾ�� 't')
		inention -> enention (�� 'i' �滻Ϊ 'e')
		enention -> exention (�� 'n' �滻Ϊ 'x')
		exention -> exection (�� 'n' �滻Ϊ 'c')
		exection -> execution (���� 'u')
*/