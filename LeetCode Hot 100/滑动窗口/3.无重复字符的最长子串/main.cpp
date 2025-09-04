#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int result = 0;
			int len = s.size();
			unordered_map<char, int> mp;
			int left = -1, right = 0;	// 定义双指针
			while (right < len) {
				auto iter = mp.find(s[right]);
				if (iter != mp.end()) {
					left = max(left, iter->second); // 更新左指针
				}
				mp[s[right]] = right; // 哈希表记录位置
				result = max(result, right - left);
				right++;
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "abcabcbb";
	cout << solution.lengthOfLongestSubstring(s);
}