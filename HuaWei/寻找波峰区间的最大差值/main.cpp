#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> area(n);
	for (int i = 0; i < n; ++i)
		cin >> area[i];

	int ans = 0;
	int i = 0;
	while (i < n) {
		// 找到峰顶区间
		int peak_l = i, peak_r = i;
		// 平台峰（向右扩展相等值）
		while (peak_r + 1 < n && area[peak_r + 1] == area[peak_l])
			++peak_r;

		// 左扩展（非递减）
		int l = peak_l;
		while (l - 1 >= 0 && area[l - 1] <= area[l])
			--l;
		// 右扩展（非递增）
		int r = peak_r;
		while (r + 1 < n && area[r + 1] <= area[r])
			++r;

		// 统计当前区间最大最小
		int maxi = area[l], mini = area[l];
		for (int j = l + 1; j <= r; ++j) {
			maxi = max(maxi, area[j]);
			mini = min(mini, area[j]);
		}
		ans = max(ans, maxi - mini);

		// 跳到右侧下一个区间
		i = peak_r + 1;
	}

	cout << ans << endl;
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 检查区间[start, end]是否满足先非递减再非递增的条件
bool isValidInterval(const vector<int>& area, int start, int end) {
    if (start == end) return true; // 单个元素总是满足条件

    // 找到第一个递减的位置
    int peakEnd = start;
    while (peakEnd < end && area[peakEnd] <= area[peakEnd + 1]) {
        peakEnd++;
    }

    // 检查从peakEnd开始是否都是非递增的
    for (int i = peakEnd; i < end; i++) {
        if (area[i] < area[i + 1]) {
            return false; // 出现递增，不满足条件
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> area(n);
    for (int i = 0; i < n; i++) {
        cin >> area[i];
    }

    int maxDiff = 0;

    // 枚举所有可能的区间
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isValidInterval(area, i, j)) {
                // 计算该区间的最大值和最小值
                int maxVal = area[i], minVal = area[i];
                for (int k = i; k <= j; k++) {
                    maxVal = max(maxVal, area[k]);
                    minVal = min(minVal, area[k]);
                }

                // 更新最大差值
                maxDiff = max(maxDiff, maxVal - minVal);
            }
        }
    }
    cout << maxDiff << endl;

    return 0;
}
*/
/*
示例分析：
8
1 2 3 5 4 4 8 1
输入：[1, 2, 3, 5, 4, 4, 8, 1]
索引： 0  1  2  3  4  5  6  7

关键的满足条件的区间：
1. [0,1,2,3,4] = [1,2,3,5,4]:
   - 非递减部分：1≤2≤3≤5 (索引0到3)
   - 非递增部分：5≥4 (索引3到4)
   - 最大值5，最小值1，差值4

2. [4,5,6,7] = [4,4,8,1]:
   - 非递减部分：4≤4≤8 (索引4到6)
   - 非递增部分：8≥1 (索引6到7)
   - 最大值8，最小值1，差值7

3. [5,6,7] = [4,8,1]:
   - 非递减部分：4≤8 (索引5到6)
   - 非递增部分：8≥1 (索引6到7)
   - 最大值8，最小值1，差值7

4. [6,7] = [8,1]:
   - 只有非递增部分：8≥1
   - 最大值8，最小值1，差值7

最大差值为7。
*/