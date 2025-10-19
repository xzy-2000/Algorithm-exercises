#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool is_covered(unordered_map<char, int> &cnt_s, unordered_map<char, int> &cnt_t) {
			for (int i = 'A'; i <= 'Z'; i++) {
				if (cnt_s[i] < cnt_t[i])
					return false;
			}
			for (int i = 'a'; i <= 'z'; i++) {
				if (cnt_s[i] < cnt_t[i])
					return false;
			}
			return true;
		}
	public:
		string minWindow(string s, string t) {
			int n_s = s.size(), n_t = t.size();
			unordered_map<char, int> cnt_s;
			unordered_map<char, int> cnt_t;
			for (int i = 0; i < n_t; i++) {
				cnt_t[t[i]]++;
			}
			int left = 0;
			int ans_left = -1, ans_right = n_s;
			for (int right = 0; right < n_s; right++) {
				// 右窗口进入
				cnt_s[s[right]]++;

				while (is_covered(cnt_s, cnt_t)) {
					if (ans_right - ans_left > right - left) {
						ans_right = right;
						ans_left = left;
					}
					// 左窗口移除
					cnt_s[s[left]]--;
					left++;
				}
			}
			if (ans_left < 0) {
				return "";
			}
			return s.substr(ans_left, ans_right - ans_left + 1);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "ADOBECODEBANC", t = "ABC";
	cout << solution.minWindow(s, t);
	return 0;
}

