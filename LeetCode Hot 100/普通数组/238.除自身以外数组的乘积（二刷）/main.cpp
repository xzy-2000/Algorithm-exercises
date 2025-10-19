#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ǰ׺��
		vector<int> productExceptSelf(vector<int> &nums) {
			int n = nums.size();
			// ���� pre[i] ��ʾ�� nums[0] �� nums[i-1] �ĳ˻�
			vector<int> pre(n + 1, 1);
			// ���� suf[i] ��ʾ�� nums[i+1] �� nums[n-1] �ĳ˻�
			vector<int> suf(n + 1, 1);
			pre[0] = nums[0];
			for (int i = 1; i < n; i++) {
				pre[i] = nums[i] * pre[i - 1];
			}
			for (int i = n - 1; i >= 0; i--) {
				suf[i] = nums[i] * suf[i + 1];
			}
			vector<int> multiply(n);
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					multiply[i] = suf[i + 1];
				} else if (i == n - 1) {
					multiply[i] = pre[i - 1];
				} else {
					multiply[i] = pre[i - 1] * suf[i + 1];
				}
			}
			return multiply;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3, 4};
	vector<int> res = solution.productExceptSelf(nums);
	for (int n : res) {
		cout << n << " ";
	}
	return 0;
}