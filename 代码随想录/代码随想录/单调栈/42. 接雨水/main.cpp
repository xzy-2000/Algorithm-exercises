#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 暴力
		int trap(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			for (int i = 0; i < size; i++) {
				// 第一个和最后一个不接雨水
				if (i == 0 || i == size - 1)
					continue;
				// 双指针法遍历
				int rHeight = height[i]; // 记录右边柱子的最高高度
				int lHeight = height[i]; // 记录左边柱子的最高高度
				// 遍历右边
				for (int r = i + 1; r < size; r++) {
					if (height[r] > rHeight) {
						rHeight = height[r];
					}
				}
				// 遍历左边
				for (int l = i - 1; l >= 0; l--) {
					if (height[l] > lHeight) {
						lHeight = height[l];
					}
				}
				result += max(min(rHeight, lHeight) - height[i], 0);
			}
			return result;
		}
		// 双指针优化
		int trap2(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			vector<int> maxLeft(size, 0);
			vector<int> maxRight(size, 0);

			// 记录每个柱子左边柱子最大高度
			maxLeft[0] = height[0];
			for (int i = 1; i < size; i++) {
				maxLeft[i] = max(height[i], maxLeft[i - 1]);
			}
			// 记录每个柱子右边柱子最大高度
			maxRight[size - 1] = height[size - 1];
			for (int i = size - 2; i >= 0; i--) {
				maxRight[i] = max(height[i], maxRight[i + 1]);
			}
			// 求和
			int sum = 0;
			for (int i = 0; i < size; i++) {
				int count = min(maxLeft[i], maxRight[i]) - height[i];
				if (count > 0)
					sum += count;
			}
			return sum;
		}
		// 单调栈
		int trap3(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
			st.push(0);
			for (int i = 1; i < size; i++) {
				if (height[i] < height[st.top()]) {
					st.push(i);
				} else if (height[i] == height[st.top()]) {
					st.pop();
					st.push(i);
				} else {
					while (!st.empty() && height[i] > height[st.top()]) {
						int mid = st.top();
						st.pop();
						if (!st.empty()) {
							int h = min(height[i], height[st.top()]) - height[mid];
							int w = abs(st.top() - i) - 1;
							result += w * h;
						}
					}
					st.push(i);
				}
			}
			return result;
		}
};

int main() {
	Solution solution;

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int cnt = solution.trap(height);
	cout << cnt << endl;

	int cnt2 = solution.trap2(height);
	cout << cnt2 << endl;

	int cnt3 = solution.trap3(height);
	cout << cnt3 << endl;
	return 0;
}

/*

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6

输入：height = [4,2,0,3,2,5]
输出：9

*/