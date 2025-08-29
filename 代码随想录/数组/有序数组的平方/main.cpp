#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
	int k = nums.size() - 1;
	vector<int> result(nums.size(), 0);
	int i = 0, j = nums.size() - 1;
	while (i <= j) {
		if (nums[i]*nums[i] < nums[j]*nums[j]) {
			result[k--] = nums[j] * nums[j];
			j--;
		} else {
			result[k--] = nums[i] * nums[i];
			i++;
		}
	}
	return result;
}

int main(int argc, char **argv) {

	vector<int> nums = {-4, -1, 0, 3, 10};
	vector<int> result = sortedSquares(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}