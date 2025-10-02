#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> productExceptSelf(vector<int> &nums) {
			int n = nums.size();

			// 定义 pre[i] 表示从 nums[0] 到 nums[i-1] 的乘积
			vector<int> pre(n, 1);
			for (int i = 1; i < n; i++) {
				pre[i] = pre[i - 1] * nums[i - 1];
			}

			// 定义 suf[i] 表示从 nums[i+1] 到 nums[n-1] 的乘积
			vector<int> suf(n, 1);
			for (int i = n - 2; i >= 0; i--) {
				suf[i] =  suf[i + 1] * nums[i + 1];
			}

			vector<int> ans(n);
			for (int i = 0; i < n; i++) {
				ans[i] = pre[i] * suf[i];
			}

			return ans;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3, 4,};
	vector<int> res = solution.productExceptSelf(nums);
	for (int n : res) {
		cout << n << " ";
	}
	return 0;
}