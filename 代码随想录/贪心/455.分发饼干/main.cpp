#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findContentChildren(vector<int> &g, vector<int> &s) {
			// ̰�� s:����  g:θ��
			// �þ����ܶ�ĺ��ӳԵ����ɣ���ÿ������Ȩ����ͬ������
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
			// ����θ��
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

	vector<int> g = {10, 9, 8, 7};	// ���ӵ�θ��

	vector<int> s = {5, 6, 7, 8};	// ���ɵĴ�С
	Solution solution;
	std::cout << solution.findContentChildren(g, s);
	return 0;
}