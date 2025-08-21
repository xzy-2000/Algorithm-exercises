#include <bits/stdc++.h>
using namespace std;

//// ���������ݷ�Χ
//class Solution {
//	public:
//		vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//			unordered_set<int> result_set; // ��Ž����֮������set��Ϊ�˸������ȥ��
//			int hash[1005] = {0}; // Ĭ����ֵΪ0
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
			unordered_set<int> result_set;// ��Ž����֮������set��Ϊ�˸������ȥ��
			// ͨ�� unordered_set<int> nums_set(nums1.begin(), nums1.end())
			// ����һ�������Ԫ�ش����ϣ���ϣ��Զ����ȥ��
			unordered_set<int> nums_set(nums1.begin(), nums1.end());//
			for (int num : nums2) {
				/*
				1. nums_set.find(num) ������
				find() �� unordered_set �ĳ�Ա�����������ڼ����в���ָ����Ԫ�� num��
				����ֵ��
				��� num �����ڼ����У�����һ��ָ���Ԫ�صĵ�������������ָ�룩��
				��� num �����ڣ�����һ������ĵ����� nums_set.end()��

				2. nums_set.end() �ĺ���
				end() �� unordered_set �ĳ�Ա����������һ��ָ�򼯺ϡ�ĩβ���ĵ�������
				�����������ָ���κ�ʵ��Ԫ�أ�ֻ��������ʶ����ʧ�ܵ������
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