#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> findAnagrams(string s, string p) {
			vector<int> sCnt(26, 0);
			vector<int> pCnt(26, 0);
			vector<int> result;
			int len = p.size();
			for (char c : p) {
				pCnt[c - 'a']++;
			}
			for (int left = 0, right = 0; right < s.size(); ++right) {
				// �����ұߵ�Ԫ��
				sCnt[s[right] - 'a']++;

				// ���ڳ���p����ʱ������ַ�Ƶ�μ�һ����ָ������
				if (right - left + 1 > len) {
					// ȥ����ߵ�Ԫ��
					sCnt[s[left] - 'a']--;
					left++;
				}
				if (right - left + 1 == len && sCnt == pCnt) {
					result.push_back(left);
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