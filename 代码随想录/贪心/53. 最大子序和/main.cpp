#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ̰��
		int maxSubArray1(vector<int> &nums) {
			int result = 0;
			int Maxn = INT32_MIN;
			// ��������ʼ����������
			for (int i = 0; i < nums.size(); i++) {
				result += nums[i];
				if (result > Maxn) {
					Maxn = result;
				}
				if (result <= 0)
					// �൱���������������ʼλ�ã���Ϊ��������һ���������ܺ�
					result = 0;
			}
			return Maxn;
		}
		// ��̬�滮
		int maxSubArray(vector<int> &nums) {
			int size = nums.size();
			if (size == 0)
				return 0;
			vector<int> dp(size, 0);
			int result = dp[0];
			// dp[0] = max(nums[0], 0); ���ٰ���һ��Ԫ��
			dp[0] = nums[0];
			for (int i = 1; i < size; i++) {
				dp[i] = max(dp[i - 1] + nums[i], nums[i]);
				if (dp[i] > result)
					result = dp[i]; // result ����dp[i]�����ֵ
			}
			return result;
		}
};
int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	std::cout << solution.maxSubArray(nums);
	return 0;
}
/*
����: [-2,1,-3,4,-1,2,1,-5,4]
���: 6
*/