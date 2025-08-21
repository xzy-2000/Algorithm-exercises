#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int wiggleMaxLength(vector<int> &nums) {
			if (nums.size() <= 1)
				return nums.size();
			int curDiff = 0; // ��ǰһ�Բ�ֵ
			int preDiff = 0; // ǰһ�Բ�ֵ
			int result = 1;  // ��¼��ֵ����������Ĭ���������ұ���һ����ֵ
			int flag = 1;
			switch (flag) {
				//̰��
				case 0:
//					cout << "̰��";
					for (int i = 0; i < nums.size() - 1; i++) {
						curDiff = nums[i + 1] - nums[i];
						// ���ַ�ֵ
						if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) {
							result++;
							preDiff = curDiff;
						}
					}
					break;
				//��̬�滮
				case 1:
//					cout << "��̬�滮";
// �� dp ״̬dp[i][0]����ʾ����ǰ i �������� i ������Ϊɽ��İڶ������е������
// �� dp ״̬dp[i][1]����ʾ����ǰ i �������� i ������Ϊɽ�ȵİڶ������е������
					vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
					//��ʼ��
					dp[0][0] = 1;
					dp[0][1] = 1;
					//����
					for (int i = 1; i < nums.size(); i++) {
						dp[i][0] = dp[i][1] = 1;
						//״̬ת�Ʒ���
						for (int j = 0; j < i; ++j) {
							if (nums[i] < nums[j]) {
								dp[i][1] = max(dp[i][1], dp[j][0] + 1);
							}
						}
						for (int j = 0; j < i; ++j) {
							if (nums[i] > nums[j]) {
								dp[i][0] = max(dp[i][0], dp[j][1] + 1);
							}
						}
					}
					result = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
					break;
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 7, 4, 9, 2, 5};
	cout << solution.wiggleMaxLength(nums);
	return 0;
}