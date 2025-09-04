#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int result = 0;
			int len = s.size();
			unordered_map<char, int> mp;
			int left = -1, right = 0;	// ����˫ָ��
			while (right < len) {
				auto iter = mp.find(s[right]);
				if (iter != mp.end()) {
					left = max(left, iter->second); // ������ָ��
				}
				mp[s[right]] = right; // ��ϣ���¼λ��
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