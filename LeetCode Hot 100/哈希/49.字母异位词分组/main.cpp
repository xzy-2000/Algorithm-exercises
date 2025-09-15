#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string> &strs) {
			vector<vector<string>> result;
			unordered_map<string, vector<string>> mp;
			for (const auto &str : strs) {
				auto temp(str);
				sort(temp.begin(), temp.end());
				mp[temp].emplace_back(str);
			}
			for (const auto &s : mp) {
				result.emplace_back(s.second);
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