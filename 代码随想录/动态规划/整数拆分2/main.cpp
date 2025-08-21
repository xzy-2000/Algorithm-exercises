#include <iostream>
#include <vector>
using namespace std;

int countSplits(int n) {
	if (n == 0)
		return 0;

	vector<int> dp_even(n + 1, 0); // 以偶数结尾的拆分方式数
	vector<int> dp_odd(n + 1, 0);  // 以奇数结尾的拆分方式数

	// 前缀和数组，用于快速计算累加
	vector<int> prefix_even(n + 1, 0);
	vector<int> prefix_odd(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		// 计算dp_even[i]
		if (i >= 2) {
			// 累加所有dp_odd[i-2k]，k≥1，即i-2, i-4,...
			// 这相当于prefix_odd[i-2]中每隔一个数的和
			dp_even[i] = prefix_odd[i - 2];
		}
		if (i % 2 == 0) {
			dp_even[i] += 1; // 单独拆分为i
		}

		// 计算dp_odd[i]
		if (i >= 1) {
			// 累加所有dp_even[i - (2k+1)]，即i-1, i-3,...
			// 这相当于prefix_even[i-1]中每隔一个数的和
			dp_odd[i] = prefix_even[i - 1];
		}
		if (i % 2 == 1) {
			dp_odd[i] += 1; // 单独拆分为i
		}

		// 更新前缀和
		prefix_even[i] = prefix_even[i - 1] + dp_even[i];
		prefix_odd[i] = prefix_odd[i - 1] + dp_odd[i];
	}

	return dp_even[n] + dp_odd[n];
}

int main() {
	int n;
	cout << "请输入正整数n：";
	cin >> n;
	cout << "拆分方式数目为：" << countSplits(n) << endl;
	return 0;
}