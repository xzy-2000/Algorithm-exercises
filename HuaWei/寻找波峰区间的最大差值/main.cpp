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
		// �ҵ��嶥����
		int peak_l = i, peak_r = i;
		// ƽ̨�壨������չ���ֵ��
		while (peak_r + 1 < n && area[peak_r + 1] == area[peak_l])
			++peak_r;

		// ����չ���ǵݼ���
		int l = peak_l;
		while (l - 1 >= 0 && area[l - 1] <= area[l])
			--l;
		// ����չ���ǵ�����
		int r = peak_r;
		while (r + 1 < n && area[r + 1] <= area[r])
			++r;

		// ͳ�Ƶ�ǰ���������С
		int maxi = area[l], mini = area[l];
		for (int j = l + 1; j <= r; ++j) {
			maxi = max(maxi, area[j]);
			mini = min(mini, area[j]);
		}
		ans = max(ans, maxi - mini);

		// �����Ҳ���һ������
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

// �������[start, end]�Ƿ������ȷǵݼ��ٷǵ���������
bool isValidInterval(const vector<int>& area, int start, int end) {
    if (start == end) return true; // ����Ԫ��������������

    // �ҵ���һ���ݼ���λ��
    int peakEnd = start;
    while (peakEnd < end && area[peakEnd] <= area[peakEnd + 1]) {
        peakEnd++;
    }

    // ����peakEnd��ʼ�Ƿ��Ƿǵ�����
    for (int i = peakEnd; i < end; i++) {
        if (area[i] < area[i + 1]) {
            return false; // ���ֵ���������������
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

    // ö�����п��ܵ�����
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isValidInterval(area, i, j)) {
                // �������������ֵ����Сֵ
                int maxVal = area[i], minVal = area[i];
                for (int k = i; k <= j; k++) {
                    maxVal = max(maxVal, area[k]);
                    minVal = min(minVal, area[k]);
                }

                // ��������ֵ
                maxDiff = max(maxDiff, maxVal - minVal);
            }
        }
    }
    cout << maxDiff << endl;

    return 0;
}
*/
/*
ʾ��������
8
1 2 3 5 4 4 8 1
���룺[1, 2, 3, 5, 4, 4, 8, 1]
������ 0  1  2  3  4  5  6  7

�ؼ����������������䣺
1. [0,1,2,3,4] = [1,2,3,5,4]:
   - �ǵݼ����֣�1��2��3��5 (����0��3)
   - �ǵ������֣�5��4 (����3��4)
   - ���ֵ5����Сֵ1����ֵ4

2. [4,5,6,7] = [4,4,8,1]:
   - �ǵݼ����֣�4��4��8 (����4��6)
   - �ǵ������֣�8��1 (����6��7)
   - ���ֵ8����Сֵ1����ֵ7

3. [5,6,7] = [4,8,1]:
   - �ǵݼ����֣�4��8 (����5��6)
   - �ǵ������֣�8��1 (����6��7)
   - ���ֵ8����Сֵ1����ֵ7

4. [6,7] = [8,1]:
   - ֻ�зǵ������֣�8��1
   - ���ֵ8����Сֵ1����ֵ7

����ֵΪ7��
*/