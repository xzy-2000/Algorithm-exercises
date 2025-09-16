#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int> &nums, int k) {
			int len = nums.size();
			vector<int> result(len - k + 1);
			deque<int> q;

			for (int r = 0; r < len; r++) {
				// 1.������ָ�����
				while (!q.empty() && nums[q.back()] < nums[r]) {
					q.pop_back();
				}
				q.push_back(r);

				// 2.������ָ�����
				int l = r - (k - 1);
				if (l > q.front()) {
					q.pop_front();
				}

				//3. �ڴ�����˵㴦��¼��
				if (l >= 0) {
					result[l] = nums[q.front()];
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	vector<int> Window = solution.maxSlidingWindow(nums, k);
	for (const auto n : Window ) {
		cout << n << " ";
	}
	return 0;
}

