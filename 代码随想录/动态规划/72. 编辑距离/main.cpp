#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minDistance(string word1, string word2) {
			// 定义dp数组含义和初始化
			// dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，
			// 想要达到相等，所需要删除元素的最少次数。
			vector<vector<uint64_t>> dp(word1.size() + 1, vector<uint64_t>(word2.size() + 1, 0));
			// 初始化
			// dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。
			for (int i = 0; i <= word1.size(); i++) {
				dp[i][0] = i;
			}
			// dp[0][j]：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。
			for (int j = 1; j <= word2.size(); j++) {
				dp[0][j] = j;
			}
			// 遍历
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
输入：word1 = "intention", word2 = "execution"

输出：5

解释：  intention -> inention (删除 't')
		inention -> enention (将 'i' 替换为 'e')
		enention -> exention (将 'n' 替换为 'x')
		exention -> exection (将 'n' 替换为 'c')
		exection -> execution (插入 'u')
*/