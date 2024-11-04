#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;

int X[maxn], F[maxn];

//inline int gi()
//{
//	char c;int num=0,flg=1;
//	while((c=getchar())<'0'||c>'9')if(c=='-')flg=-1;
//	while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
//	return num*flg;
//}

int main() {
	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> X[i];
	for (int i = 1; i <= N; i++) {
		cin >> F[i];
		F[i]++;
	}
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++) {
			if (F[i] != j && F[j] != i)//不相邻的两个结点
				ans = max(ans, X[i] ^ X[j]);
		}
	cout << ans;
	return 0;
}

/*
5
1 0 5 3 4
-1 0 1 0 1
*/