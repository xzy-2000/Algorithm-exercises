#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;
int a[maxn], sum[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
//  for (int i = 0; i < n; i++) {
//      cout << sum[i] << endl;
//  }
	int left, right;
	while (~scanf("%d%d", &left, &right)) {
		int Sum;
		if (left == 0) {
			Sum = sum[right + 1];
		} else
			Sum = sum[right + 1] - sum[left];
		cout << Sum << endl;
	}
}