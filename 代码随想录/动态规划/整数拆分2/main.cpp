#include <iostream>
#include <vector>
using namespace std;

int countSplits(int n) {
	if (n == 0)
		return 0;

	vector<int> dp_even(n + 1, 0); // ��ż����β�Ĳ�ַ�ʽ��
	vector<int> dp_odd(n + 1, 0);  // ��������β�Ĳ�ַ�ʽ��

	// ǰ׺�����飬���ڿ��ټ����ۼ�
	vector<int> prefix_even(n + 1, 0);
	vector<int> prefix_odd(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		// ����dp_even[i]
		if (i >= 2) {
			// �ۼ�����dp_odd[i-2k]��k��1����i-2, i-4,...
			// ���൱��prefix_odd[i-2]��ÿ��һ�����ĺ�
			dp_even[i] = prefix_odd[i - 2];
		}
		if (i % 2 == 0) {
			dp_even[i] += 1; // �������Ϊi
		}

		// ����dp_odd[i]
		if (i >= 1) {
			// �ۼ�����dp_even[i - (2k+1)]����i-1, i-3,...
			// ���൱��prefix_even[i-1]��ÿ��һ�����ĺ�
			dp_odd[i] = prefix_even[i - 1];
		}
		if (i % 2 == 1) {
			dp_odd[i] += 1; // �������Ϊi
		}

		// ����ǰ׺��
		prefix_even[i] = prefix_even[i - 1] + dp_even[i];
		prefix_odd[i] = prefix_odd[i - 1] + dp_odd[i];
	}

	return dp_even[n] + dp_odd[n];
}

int main() {
	int n;
	cout << "������������n��";
	cin >> n;
	cout << "��ַ�ʽ��ĿΪ��" << countSplits(n) << endl;
	return 0;
}