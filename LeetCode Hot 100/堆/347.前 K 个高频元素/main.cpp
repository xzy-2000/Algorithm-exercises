#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> topKFrequent(vector<int> &nums, int k) {
			// 1.������ϣ��洢ÿ��Ԫ�س��ִ���
			unordered_map<int, int> cnt;
			int max_cnt = 0;
			for (int x : nums) {
				cnt[x]++;
				max_cnt = max(max_cnt, cnt[x]);
			}

			// 2.�ѳ��ִ�����ͬ��Ԫ�أ��ŵ�ͬһ��Ͱ��
			vector<vector<int>> buckets(max_cnt + 1); // buckets[c]��c������ִ�����buckets[c]={}����洢��Ԫ������
//			for (auto& [x, c] : cnt) {
//				buckets[c].push_back(x);
//			}
			// it ��һ��������
			for (auto it = cnt.begin(); it != cnt.end(); ++it) {
				// it->first �Ǽ�, it->second ��ֵ
				buckets[it->second].push_back(it->first);
			}

			// 3.������� buckets���ѳ��ִ���ǰ k ���Ԫ�ؼ����
			vector<int> result(k);
			int idx = 0; // �������ĵ�ǰλ��
			// ��������Ͱ����С����Ͱ����
			for (int i = max_cnt; i >= 0; i--) {
				// ������ǰͰ����������֣����ǳ��ִ���Ϊ i �����֣�
				for (int num : buckets[i]) {
					// �����ַŽ�������飬ֱ���ռ��� k ��
					result[idx++] = num;
					// ����Ѿ��ռ��� k ����ֱ�ӷ��ؽ��
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
