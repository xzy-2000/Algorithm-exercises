#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]��������i���������ֽ�
			// dp[i][0]��û�в���
			// dp[i][1]�ǵ�һ�γ��й�Ʊ��dp[i][2]�ǵ�һ�β����й�Ʊ
			// dp[i][3]�ǵڶ��γ��й�Ʊ��dp[i][4]�ǵڶ��β����й�Ʊ
			vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
			// ��ʼ��dp����
			dp[0][1] = -prices[0];
			dp[0][3] = -prices[0];

			for (int i = 1; i < prices.size(); i++) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
				dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
				dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
				dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
			}
			return max(max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]), dp[prices.size() - 1][4]);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	std::cout << solution.maxProfit(prices);
	return 0;
}
/*
ʾ�� 1:

���룺prices = [3,3,5,0,0,3,1,4]

�����6 ���ͣ��ڵ� 4 �죨��Ʊ�۸� = 0����ʱ�����룬�ڵ� 6 �죨��Ʊ�۸� = 3����ʱ����������ʽ������ܻ������ = 3-0 = 3 ������ڵ� 7 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 8 �� ����Ʊ�۸� = 4����ʱ����������ʽ������ܻ������ = 4-1 = 3��

ʾ�� 2��

���룺prices = [1,2,3,4,5]

�����4 ���ͣ��ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4��ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�������������Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��

ʾ�� 3��

���룺prices = [7,6,4,3,1]

�����0 ���ͣ�����������, û�н������, �����������Ϊ0��

ʾ�� 4��

���룺prices = [1] �����0
*/