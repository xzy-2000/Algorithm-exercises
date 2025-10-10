#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> findAnagrams(string s, string p) {
			unordered_map<char, int> mp;
			vector<int> res;
			int l = 0;
			int n = s.size(), len = p.size();
			for (int i = 0; i < len; i++) {
				mp[p[i]]++;
			}
			for (int r = 0; r < n; r++) {
				// �Ҵ��ڽ���
				mp[s[r]]--;
				// Ԫ�����
				while (mp[s[r]] < 0) {
					// �󴰿��Ƴ�
					mp[s[l]]++;
					l++;
				}
				// �������������
				if (r - l + 1 == len) {
					res.push_back(l);
				}
			}
			return res;
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
