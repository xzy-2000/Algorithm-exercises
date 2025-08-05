#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(int k, vector<int> &prices) {
			int len = prices.size();
			if (len == 0)
				return 0;
			// �����ǳ��У�ż���ǲ�����
			vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
			// ��ʼ��
			for (int j = 1; j < 2 * k; j += 2) {
				dp[0][j] = -prices[0];
			}
			// ����
			for (int i = 1; i < len; i++) {
				for (int j = 1; j < 2 * k; j = j + 2) {
					// ���� 2k-1
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
					// ������ 2k
					dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
				}
			}
			return dp[len - 1][2 * k];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int k = 2;

	vector<int> prices = {3, 2, 6, 5, 0, 3};
	std::cout << solution.maxProfit(k, prices);
	return 0;
}
/*
ʾ�� 1��

���룺k = 2, prices = [2,4,1]

�����2 ���ͣ��ڵ� 1 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 2 �� (��Ʊ�۸� = 4) ��ʱ����������ʽ������ܻ������ = 4-2 = 2��

ʾ�� 2��

���룺k = 2, prices = [3,2,6,5,0,3]

�����7 ���ͣ��ڵ� 2 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 3 �� (��Ʊ�۸� = 6) ��ʱ������, ��ʽ������ܻ������ = 6-2 = 4������ڵ� 5 �� (��Ʊ�۸� = 0) ��ʱ�����룬�ڵ� 6 �� (��Ʊ�۸� = 3) ��ʱ������, ��ʽ������ܻ������ = 3-0 = 3 ��
*/