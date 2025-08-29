#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	int sum = 0, result = INT_MAX;
//	vector<vector<int>> vec(n, vector<int>(m, 0));
	int vec[maxn + 1][maxn + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> vec[i][j];
			sum += vec[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vec[i][j] += vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
		}
	}

//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << vec[i][j] << " ";
//		}
//		cout << endl;
//	}

	for (int i = 1; i <= n; i++) {
		result = min(result, abs(sum - vec[i][m] - vec[i][m]));
	}

	for (int j = 1; j <= m; j++) {
		result = min(result, abs(sum - vec[n][j] - vec[n][j]));
	}
	cout << result;
	return 0;
}
/*
3 3
1 2 3
2 1 3
1 2 3
*/