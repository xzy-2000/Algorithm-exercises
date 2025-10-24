#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string> &strs) {
			vector<vector<string>> result;
			unordered_map<string, vector<string>> mp;
			for (auto str : strs) {
				string sort_str = str;
				sort(sort_str.begin(), sort_str.end());
				mp[sort_str].emplace_back(str);
			}
			for (auto [key, value] : mp) {
				result.emplace_back(value);
			}
			return result;
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
		cout << endl;
	}
	return 0;
}

