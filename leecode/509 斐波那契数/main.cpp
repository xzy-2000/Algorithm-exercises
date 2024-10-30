#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	int f0 = 0, f1 = 1;
	int sum = 0;
	if (n >= 2)
		sum = fib(n - 1) + fib(n - 2);
	else if (n == 1)
		sum += f1;
	else
		sum += f0;
	return sum;
}

int main(int argc, char **argv) {
	int n, m;
	cin >> n;
	m = fib(n);
	cout << m;
	return 0;
}