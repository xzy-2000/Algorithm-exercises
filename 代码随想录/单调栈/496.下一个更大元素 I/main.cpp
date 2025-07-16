#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
			int size = nums1.size();
			vector<int> result(size, -1);
			if (size == 0)
				return result;
			stack<int> st;
			unordered_map<int, int> umap;

			for (int i = 0 ; i < size; i++) {
				umap[nums1[i]] = i;
			}
			for (int i = 0 ; i < nums2.size(); i++) {
				while (!st.empty() && nums2[i] > nums2[st.top()]) {
					if (umap.count(nums2[st.top()]) > 0) {
						int index = umap[nums2[st.top()]];
						result[index] = nums2[i];
					}
					st.pop();
				}
				st.push(i);
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums1 = {4, 1, 2};
	vector<int> nums2 = {1, 3, 4, 2};
	vector<int> result = solution.nextGreaterElement(nums1, nums2);
	for (auto x : result) {
		cout << x << " ";
	}
	return 0;
}