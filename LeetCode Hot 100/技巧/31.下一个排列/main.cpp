#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void nextPermutation(vector<int> &nums) {
			int n = nums.size();

			// ��һ�������������ҵ���һ��С���Ҳ��������ֵ��� nums[i] 1 3 5 4 2 �ҵ���3
			int i = n - 2;
			while (i >= 0 && nums[i] >= nums[i + 1]) {
				i--;
			}

			// ����ҵ��ˣ�����ڶ��������������ڶ�������ת��������
			if (i >= 0) {
				// �ڶ��������������ҵ� nums[i] �ұ���С�Ĵ��� nums[i] ���� nums[j] 3��С�Ĵ���3����Ϊ4
				int j = n - 1;
				while (nums[j] <= nums[i]) {
					j--;
				}
				cout << i << " " << j << endl;
				// ���� nums[i] �� nums[j]
				swap(nums[i], nums[j]);
			}
			// ����������ת [i+1, n-1]��������������ڶ�������ʱ i = -1��
			reverse(nums.begin() + i + 1, nums.end());
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, 5, 4, 2};
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	solution.nextPermutation(nums); // 1 4 2 3 5
	for (int n : nums) {
		cout << n << " ";
	}
	return 0;
}