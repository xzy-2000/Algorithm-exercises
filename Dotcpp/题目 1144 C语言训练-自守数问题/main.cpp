#include <bits/stdc++.h>

using namespace std;

bool IsSelfNum(int i, int len) {
	long long int x;
	long long int num;
	x = pow(i, 2);
	num = pow(10, len);
	if (x % num == i)
		return true;
	return false;
}

int main() {
	int len, ans;
	for (int i = 0; i <= 200000; i++) {
		len = 1;
		ans = i;
		while (ans / 10 >= 1) {
			len++;
			ans /= 10;
		}
		if (IsSelfNum(i, len))
			printf("%d  ", i);
	}
	return 0;
}
/*
0  1  5  6  25  76  376  625  9376  90625  109376
*/