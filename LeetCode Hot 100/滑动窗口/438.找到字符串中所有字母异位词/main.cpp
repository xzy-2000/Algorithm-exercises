#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> findAnagrams(string s, string p) {
			unordered_map<char, int> need, window;
			for (char c : p)
				need[c]++;

			vector<int> result;
			int len = p.size();
			int left = 0, right = 0;
			int valid = 0;
			while (right < s.size()) {
				char c = s[right];
				right++;
				// ���д��������ݵ�һϵ�и���
				if (need.find(c) != need.end()) {
					window[c]++;
					if (window[c] == need[c])
						valid++;
				}
				while (right - left >= len) {
					// �����ڷ�������ʱ������ʼ�������� res
					if (valid == need.size())
						result.push_back(left);
					char d = s[left];
					left++;
					// ���д��������ݵ�һϵ�и���
					if (need.find(d) != need.end()) {
						if (window[d] == need[d])
							valid--;
						window[d]--;
					}
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "cbaebabacd", p = "abc";
	vector<int> result = solution.findAnagrams(s, p);

	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}