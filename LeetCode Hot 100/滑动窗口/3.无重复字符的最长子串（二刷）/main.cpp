#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int n = s.size();
			int left = 0, cnt = 0;
			unordered_map<char, int> mp; // 维护从下标 left 到下标 right 的字符
			for (int right = 0; right < n; right++) {
				// 右窗口进入
				mp[s[right]]++;
				while (mp[s[right]] > 1) {
					// 左窗口右移
					mp[s[left]]--;
					left++;
				}
				cnt = max(cnt, right - left + 1);
			}
			return cnt;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "abcabcbb";
	cout << solution.lengthOfLongestSubstring(s);
}
