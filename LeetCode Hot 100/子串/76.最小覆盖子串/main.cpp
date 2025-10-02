#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool iscovered(unordered_map<int, int> &cnt_s, unordered_map<int, int> &cnt_t) {
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
			unordered_map<int, int> cnt_s; // s 子串字母的出现次数
			unordered_map<int, int> cnt_t; // t 中字母的出现次数
			for (char c : t) {
				cnt_t[c]++;
			}

			int m = s.size();
			int ans_left = -1, ans_right = m;

			int left = 0;
			for (int right = 0; right < m; right++) { // 移动子串右端点
				// 先移动右窗口
				cnt_s[s[right]]++; // 右端点字母移入子串
				// 再移动
				while (iscovered(cnt_s, cnt_t)) {
					if (right - left < ans_right - ans_left) { // 找到更短的子串
						ans_right = right;// 记录此时的左右端点
						ans_left = left;
					}
					cnt_s[s[left]]--; // 左端点字母移出子串
					left++;
				}
			}
//			cout << ans_left << " " << ans_right << endl;
			if (ans_left < 0)
				return "";
			return s.substr(ans_left, ans_right - ans_left + 1);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "ADOBECODEBANC", t = "ABC";
	cout << solution.minWindow(s, t);
	return 0;
}