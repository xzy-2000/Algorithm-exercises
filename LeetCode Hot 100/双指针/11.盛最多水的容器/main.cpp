#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxArea(vector<int> &height) {
			int result = 0, area;
			int left = 0, right = height.size() - 1;

			while (left < right) {
				area = (right - left) * min(height[left], height[right]);
				result = max(result, area);
				if (height[left] > height[right]) {
					right--;
				} else {
					left++;
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << solution.maxArea(height);
	return 0;
}

/*
1, 8, 6, 2, 5, 4, 8, 3, 7

49
*/