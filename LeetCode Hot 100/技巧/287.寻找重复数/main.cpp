#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findDuplicate(vector<int> &nums) {
			int n = nums.size() - 1;
			int l = 1, r = n;
			while (l < r) {
				int mid = (r + l) >> 1, count = 0;
				// �����������飬ͳ������С�ڵ��� mid �����ֵĸ��� count��
				for (int i = 0; i <= n ; i++) {
					if (nums[i] <= mid)
						count++;
				}
//				cout << "mid = " << mid << " count = " << count << endl;
				// ��� count <= mid ˵�� [1, mid] ��������ڵ����֡�û�г���������ظ����ֶ����������ˡ�
				if (count <= mid) {
					l = mid + 1;
//					cout << "l = mid + 1 = " << l << endl;
				} else {
					r = mid;
//					cout << "r = mid = " << r << endl;
				}
			}
			return l;
		}
		/*
		int findDuplicate(vector<int> &nums) {
			int slow = 0, fast = 0;
			while (true) {
				slow = nums[slow];
				fast = nums[nums[fast]];
				if (fast == slow) {
					break;
				}
			}
			int finder = 0;
			while (true) {
				slow = nums[slow];
				finder = nums[finder];
				if (finder == slow) {
					return finder;
				}
			}
		}
		*/
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, 4, 2, 2};
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	cout << solution.findDuplicate(nums);
	return 0;
}