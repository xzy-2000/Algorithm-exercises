#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	ll M;
	// 先读 k 和 M
	cin >> k >> M;
	// 吸收掉上一行末尾的换行符，否则后面 getline 会直接读到空行
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// 读整行的 cost 和 profit
	string cost_line, profit_line;
	getline(cin, cost_line);
	getline(cin, profit_line);

	// 解析成本和利润到两个 vector
	vector<ll> cost, profit;
	{
		stringstream ss(cost_line);
		ll x;
		while (ss >> x)
			cost.push_back(x);
	}
	{
		stringstream ss(profit_line);
		ll x;
		while (ss >> x)
			profit.push_back(x);
	}

	int n = cost.size();
	// 把 (cost, profit) 对放到一起，并按 cost 升序排序
	vector<pair<ll, ll>> items(n);
	for (int i = 0; i < n; i++) {
		items[i] = {cost[i], profit[i]};
	}
	sort(items.begin(), items.end(),
	[](auto & a, auto & b) {
		return a.first < b.first;
	});

	// 最大堆，存当前能买得起的所有商品的利润
	priority_queue<ll> pq;
	ll capital = M;
	int idx = 0;

	// 最多做 k 天
	for (int day = 0; day < k; day++) {
		// 把所有 cost <= capital 的商品利润推进堆
		while (idx < n && items[idx].first <= capital) {
			pq.push(items[idx].second);
			idx++;
		}
		if (pq.empty())
			break;  // 买不起任何商品，提前退出

		// 取利润最大的那件商品
		capital += pq.top();
		pq.pop();
	}

	// 最终总利润 = 当前资金 - 初始资金
	cout << (capital - M) << "\n";
	return 0;
}



/*
/*
示例输入：
3
2
2 3 4
3 4 5

示例输出：
12

解释：
- 第1天：用10元买成本4的商品，获得利润5，现在有10-4+4+5=15元
- 第2天：用15元买成本3的商品，获得利润4，现在有15-3+3+4=19元
- 第3天：用19元买成本2的商品，获得利润3，现在有19-2+2+3=22元
- 总利润：5+4+3=12

另一种可能的策略：
- 第1天：买成本2的商品，利润3，现在有11元
- 第2天：买成本3的商品，利润4，现在有12元
- 第3天：买成本4的商品，利润5，现在有13元
- 总利润：3+4+5=12

两种策略都能达到最大利润12。
*/

