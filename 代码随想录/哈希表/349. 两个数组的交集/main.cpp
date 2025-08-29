#include <bits/stdc++.h>
using namespace std;

//// 声明了数据范围
//class Solution {
//	public:
//		vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//			unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
//			int hash[1005] = {0}; // 默认数值为0
//			for (int num : nums1) {
//				hash[num] = 1;
//			}
//			for (int num : nums2) {
//				if (hash[num] == 1) {
//					result_set.insert(num);
//				}
//			}
//			return vector<int>(result_set.begin(), result_set.end());
//		}
//};

class Solution {
	public:
		vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
			unordered_set<int> result_set;// 存放结果，之所以用set是为了给结果集去重
			// 通过 unordered_set<int> nums_set(nums1.begin(), nums1.end())
			// 将第一个数组的元素存入哈希集合，自动完成去重
			unordered_set<int> nums_set(nums1.begin(), nums1.end());//
			for (int num : nums2) {
				/*
				1. nums_set.find(num) 的作用
				find() 是 unordered_set 的成员函数，用于在集合中查找指定的元素 num。
				返回值：
				如果 num 存在于集合中，返回一个指向该元素的迭代器（类似于指针）。
				如果 num 不存在，返回一个特殊的迭代器 nums_set.end()。

				2. nums_set.end() 的含义
				end() 是 unordered_set 的成员函数，返回一个指向集合“末尾”的迭代器。
				这个迭代器不指向任何实际元素，只是用来标识查找失败的情况。
				*/
				if (nums_set.find(num) != nums_set.end()) {
					result_set.insert(num);
				}
			}
			return vector<int>(result_set.begin(), result_set.end());
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
	vector<int> Intersection = solution.intersection(nums1, nums2);
	for (vector<int>::iterator it = Intersection.begin(); it != Intersection.end(); it++)
		cout << *it << " ";
	return 0;
}