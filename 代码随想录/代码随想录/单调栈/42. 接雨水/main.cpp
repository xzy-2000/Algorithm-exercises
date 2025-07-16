#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ����
		int trap(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			for (int i = 0; i < size; i++) {
				// ��һ�������һ��������ˮ
				if (i == 0 || i == size - 1)
					continue;
				// ˫ָ�뷨����
				int rHeight = height[i]; // ��¼�ұ����ӵ���߸߶�
				int lHeight = height[i]; // ��¼������ӵ���߸߶�
				// �����ұ�
				for (int r = i + 1; r < size; r++) {
					if (height[r] > rHeight) {
						rHeight = height[r];
					}
				}
				// �������
				for (int l = i - 1; l >= 0; l--) {
					if (height[l] > lHeight) {
						lHeight = height[l];
					}
				}
				result += max(min(rHeight, lHeight) - height[i], 0);
			}
			return result;
		}
		// ˫ָ���Ż�
		int trap2(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			vector<int> maxLeft(size, 0);
			vector<int> maxRight(size, 0);

			// ��¼ÿ����������������߶�
			maxLeft[0] = height[0];
			for (int i = 1; i < size; i++) {
				maxLeft[i] = max(height[i], maxLeft[i - 1]);
			}
			// ��¼ÿ�������ұ��������߶�
			maxRight[size - 1] = height[size - 1];
			for (int i = size - 2; i >= 0; i--) {
				maxRight[i] = max(height[i], maxRight[i + 1]);
			}
			// ���
			int sum = 0;
			for (int i = 0; i < size; i++) {
				int count = min(maxLeft[i], maxRight[i]) - height[i];
				if (count > 0)
					sum += count;
			}
			return sum;
		}
		// ����ջ
		int trap3(vector<int> &height) {
			int result = 0;
			int size = height.size();
			if (size <= 2)
				return result;
			stack<int> st; // �����±꣬�����ʱ�����±��Ӧ�����Ӹ߶�
			st.push(0);
			for (int i = 1; i < size; i++) {
				if (height[i] < height[st.top()]) {
					st.push(i);
				} else if (height[i] == height[st.top()]) {
					st.pop();
					st.push(i);
				} else {
					while (!st.empty() && height[i] > height[st.top()]) {
						int mid = st.top();
						st.pop();
						if (!st.empty()) {
							int h = min(height[i], height[st.top()]) - height[mid];
							int w = abs(st.top() - i) - 1;
							result += w * h;
						}
					}
					st.push(i);
				}
			}
			return result;
		}
};

int main() {
	Solution solution;

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int cnt = solution.trap(height);
	cout << cnt << endl;

	int cnt2 = solution.trap2(height);
	cout << cnt2 << endl;

	int cnt3 = solution.trap3(height);
	cout << cnt3 << endl;
	return 0;
}

/*

���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
�����6

���룺height = [4,2,0,3,2,5]
�����9

*/