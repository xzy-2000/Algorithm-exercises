#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> partitionLabels(string s) {
			vector<int> result;
			int n = s.size();
			unordered_map<char, int> last;
			for (int i = 0; i < n; i++) {
				last[s[i]] = i; // 每个字母最后出现的下标
			}
			vector<int> ans;
			int start = 0, end = 0;
			for (int i = 0; i < n; i++) {
				end = max(end, last[s[i]]);
				if (i == end) {
					result.emplace_back(end - start + 1);
					start = i + 1;
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "ababcbacadefegdehijhklij";
	vector<int> result = solution.partitionLabels(s);
	for (auto num : result)
		cout << num << " ";
	return 0;
}
