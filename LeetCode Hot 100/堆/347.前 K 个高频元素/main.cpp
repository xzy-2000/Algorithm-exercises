#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> topKFrequent(vector<int> &nums, int k) {
			// 1.建立哈希表存储每种元素出现次数
			unordered_map<int, int> cnt;
			int max_cnt = 0;
			for (int x : nums) {
				cnt[x]++;
				max_cnt = max(max_cnt, cnt[x]);
			}

			// 2.把出现次数相同的元素，放到同一个桶中
			vector<vector<int>> buckets(max_cnt + 1); // buckets[c]，c代表出现次数，buckets[c]={}代表存储的元素种类
//			for (auto& [x, c] : cnt) {
//				buckets[c].push_back(x);
//			}
			// it 是一个迭代器
			for (auto it = cnt.begin(); it != cnt.end(); ++it) {
				// it->first 是键, it->second 是值
				buckets[it->second].push_back(it->first);
			}

			// 3.倒序遍历 buckets，把出现次数前 k 大的元素加入答案
			vector<int> result(k);
			int idx = 0; // 结果数组的当前位置
			// 从最大次数桶往最小次数桶遍历
			for (int i = max_cnt; i >= 0; i--) {
				// 遍历当前桶里的所有数字（都是出现次数为 i 的数字）
				for (int num : buckets[i]) {
					// 把数字放进结果数组，直到收集够 k 个
					result[idx++] = num;
					// 如果已经收集了 k 个，直接返回结果
					if (idx == k)
						return result;
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> result = solution.topKFrequent(nums, k);
	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}
