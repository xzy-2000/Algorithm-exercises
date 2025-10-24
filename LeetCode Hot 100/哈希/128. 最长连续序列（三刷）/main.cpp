#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> &nums) {
			int max_len = 0;
			unordered_set<int> st;
			for (int num : nums) {
				st.emplace(num);
			}
			for (int x : st) {
				// 该数是否在元素集合中
				if (st.find(x - 1) == st.end()) {
					int len = 0;
					while (st.find(x + len) != st.end()) {
						len++;
					}
					max_len = max(max_len, len);
				}
			}
			return max_len;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 0, 1, 2};
	cout << solution.longestConsecutive(nums);
	return 0;
}
/*
100, 4, 200, 1, 3, 2
4

0,3,7,2,5,8,4,6,0,1
9

1,0,1,2
3
*/


