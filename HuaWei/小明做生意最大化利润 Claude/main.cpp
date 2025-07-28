#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int n, k;
vector<int> cost, profit;
map<pair<int, int>, int> memo; // 记忆化搜索

// DFS + 记忆化搜索
// money: 当前可用资金, day: 当前天数, used: 已使用的商品掩码
int dfs(int money, int day, int used) {
	if (day > k)
		return 0; // 超过k天

	pair<int, int> state = {money, used};
	if (memo.find(state) != memo.end()) {
		return memo[state];
	}

	int max_profit = 0;

	// 尝试购买每种商品
	for (int i = 0; i < n; i++) {
		// 如果商品i还没用过且买得起
		if (!(used & (1 << i)) && money >= cost[i]) {
			int new_money = money - cost[i] + cost[i] + profit[i]; // 买了又卖掉后的钱
			int new_used = used | (1 << i);
			int future_profit = dfs(new_money, day + 1, new_used);
			max_profit = max(max_profit, profit[i] + future_profit);
		}
	}

	return memo[state] = max_profit;
}

int main() {
	cin >> k;
	int M;
	cin >> M;
	cin.ignore();

	string cost_line, profit_line;
	getline(cin, cost_line);
	getline(cin, profit_line);

	// 解析成本和利润
	stringstream ss1(cost_line), ss2(profit_line);
	int temp;

	while (ss1 >> temp) {
		cost.push_back(temp);
	}
	while (ss2 >> temp) {
		profit.push_back(temp);
	}

	n = cost.size();

	// 如果商品种类太多，用位掩码会有问题，需要用其他方法
	if (n > 20) {
		// 对于商品数量很大的情况，使用贪心策略
		// 按利润率排序，优先选择利润率高的
		vector<pair<double, int>> items;
		for (int i = 0; i < n; i++) {
			items.push_back({(double)profit[i] / cost[i], i});
		}
		sort(items.rbegin(), items.rend());

		vector<bool> used(n, false);
		int current_money = M;
		int total_profit = 0;

		for (int day = 1; day <= k; day++) {
			int best_choice = -1;
			int best_profit = 0;

			// 选择当前买得起且利润最大的商品
			for (auto &item : items) {
				int idx = item.second;
				if (!used[idx] && current_money >= cost[idx]) {
					if (profit[idx] > best_profit) {
						best_profit = profit[idx];
						best_choice = idx;
					}
				}
			}

			if (best_choice == -1)
				break; // 没有可买的商品

			used[best_choice] = true;
			current_money = current_money - cost[best_choice] + cost[best_choice] + profit[best_choice];
			total_profit += profit[best_choice];
		}

		cout << total_profit << endl;
	} else {
		// 商品数量较少，使用记忆化搜索
		cout << dfs(M, 1, 0) << endl;
	}

	return 0;
}

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