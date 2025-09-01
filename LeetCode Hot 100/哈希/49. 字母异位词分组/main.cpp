#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string> &strs) {
			vector<vector<string>> result;
			unordered_map<string, vector<string>> mp;
			for (auto &s : strs) {
				auto sort_pre = s;
				sort(s.begin(), s.end());
				mp[s] = sort_pre;
			}
//			for (int i = 0; i < strs.size(); i++) {
			result.emplace_back(strs);
			return result;
//			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> result = solution.groupAnagrams(strs);
	for (auto &perms : result) {
		for (string perm : perms) {
			cout << perm << " ";
		}
	}
	return 0;
}