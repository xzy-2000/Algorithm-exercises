#include <bits/stdc++.h>

using namespace std;

int arr[1000001] = {0};

int main() {
	int cnt;
	int tmp;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (arr[i])
			cout << i << ' ' << arr[i] << '\n';
	}
	return 0;
}

//#include <stdio.h>
//
//int arr[1000000];
//
//int main(void) {
//	int n;
//	scanf("%d", &n);
//
//	int tmp;
//	int i;
//	for (i = 0; i < n; i++) {
//		scanf("%d", &tmp);
//		arr[tmp]++;
//	}
//
//	for (i = 0; i < 1000000; i++) {
//		if (arr[i] != 0) {
//			printf("%d %d\n", i, arr[i]);
//		}
//	}
//
//
//	return 0;
//}

/*
12
8 2 8 2 2 11 1 1 8 1 13 13
*/

/*
1 3
2 3
8 3
11 1
13 2
*/