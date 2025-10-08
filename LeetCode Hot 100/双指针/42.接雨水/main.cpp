#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ˫ָ��
		int trap(vector<int> &height) {
			int l = 0, r = height.size() - 1;
			int sum = 0, maxL = 0, maxR = 0;
			while (l < r) {
				maxL = max(maxL, height[l]);
				maxR = max(maxR, height[r]);
				sum += maxL < maxR ? maxL - height[l++] : maxR - height[r--];
			}
			return sum;
		}
		// ����ջ
		int trap2(vector<int> &height) {
			int sum = 0;
			int n = height.size();
			if (n <= 2)
				return 0;
			stack<int> st;
			for (int i = 0; i < n; i++) {
//				cout << "i = " << i << " height[i] = " << height[i] << endl;
				int h_now = height[i]; // ��ǰλ��i�ĸ�h
				while (!st.empty() && height[st.top()] <= h_now) {
					int bottom_h = height[st.top()];
					st.pop();
					if (st.empty()) {
						break;
					}
					int h = min(height[st.top()], height[i]) - bottom_h;
					int w = (i - 1) - st.top();
					sum += h * w;
				}
				st.push(i);
			}
			return sum;
		}
};

int main() {
	Solution solution;

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	int cnt1 = solution.trap(height);
	cout << cnt1 << endl;

	int cnt2 = solution.trap2(height);
	cout << cnt2 << endl;
	return 0;
}

/*

���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
�����6

���룺height = [4,2,0,3,2,5]
�����9

*/

