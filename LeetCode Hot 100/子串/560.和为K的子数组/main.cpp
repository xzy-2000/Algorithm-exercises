#include <bits/stdc++.h>
using namespace std;

// ǰ׺�� + ��ϣ���Ż�
class Solution {
	public:
		int subarraySum(vector<int> &nums, int k) {
			int n = nums.size();
			vector<int> pre(n + 1, 0);
			for (int i = 0; i < n; i++) {
				pre[i + 1] = pre[i] + nums[i];
			}
			int result = 0;
			// ��ϣ�� mp���Ժ�Ϊ�������ִ���Ϊ��Ӧ��ֵ��
			// ��¼ pre[i] ���ֵĴ������������ұ߸��� mp �߼����
			unordered_map<int, int> mp;

			for (int j = 0; j <= n; j++) {
				auto it = mp.find(pre[j] - k);
				// ˵��֮ǰ����pre[i] - k
				if (it != mp.end()) {
					result += mp[pre[j] - k];
				}
				mp[pre[j]]++;
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 1};
	int k = 2;
	cout << solution.subarraySum(nums, k);
	return 0;
}