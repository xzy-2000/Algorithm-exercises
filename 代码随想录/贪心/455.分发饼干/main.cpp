#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findContentChildren(vector<int> &g, vector<int> &s) {
			// 贪心 s:饼干  g:胃口
			// 让尽可能多的孩子吃到饼干，且每个孩子权重相同，暴力
			int cnt = 0;
			if (s.empty() || g.empty())
				return 0;
			sort(g.begin(), g.end(), [](int x, int y) {
				return x > y;
			});
			sort(s.begin(), s.end(), [](int x, int y) {
				return x > y;
			});
			int index = 0;
			// 遍历胃口
			for (int i = 0; i < g.size(); i++) {
				if (index <= s.size() - 1 && index >= 0 && s[index] >= g[i]) {
					cnt++;
					index++;
				}
			}
			return cnt;
		}
};

int main(int argc, char **argv) {

	vector<int> g = {10, 9, 8, 7};	// 孩子的胃口

	vector<int> s = {5, 6, 7, 8};	// 饼干的大小
	Solution solution;
	std::cout << solution.findContentChildren(g, s);
	return 0;
}