#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int n, k;
vector<int> cost, profit;
map<pair<int, int>, int> memo; // ���仯����

// DFS + ���仯����
// money: ��ǰ�����ʽ�, day: ��ǰ����, used: ��ʹ�õ���Ʒ����
int dfs(int money, int day, int used) {
	if (day > k)
		return 0; // ����k��

	pair<int, int> state = {money, used};
	if (memo.find(state) != memo.end()) {
		return memo[state];
	}

	int max_profit = 0;

	// ���Թ���ÿ����Ʒ
	for (int i = 0; i < n; i++) {
		// �����Ʒi��û�ù��������
		if (!(used & (1 << i)) && money >= cost[i]) {
			int new_money = money - cost[i] + cost[i] + profit[i]; // �������������Ǯ
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

	// �����ɱ�������
	stringstream ss1(cost_line), ss2(profit_line);
	int temp;

	while (ss1 >> temp) {
		cost.push_back(temp);
	}
	while (ss2 >> temp) {
		profit.push_back(temp);
	}

	n = cost.size();

	// �����Ʒ����̫�࣬��λ����������⣬��Ҫ����������
	if (n > 20) {
		// ������Ʒ�����ܴ�������ʹ��̰�Ĳ���
		// ����������������ѡ�������ʸߵ�
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

			// ѡ��ǰ�����������������Ʒ
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
				break; // û�п������Ʒ

			used[best_choice] = true;
			current_money = current_money - cost[best_choice] + cost[best_choice] + profit[best_choice];
			total_profit += profit[best_choice];
		}

		cout << total_profit << endl;
	} else {
		// ��Ʒ�������٣�ʹ�ü��仯����
		cout << dfs(M, 1, 0) << endl;
	}

	return 0;
}

/*
ʾ�����룺
3
2
2 3 4
3 4 5

ʾ�������
12

���ͣ�
- ��1�죺��10Ԫ��ɱ�4����Ʒ���������5��������10-4+4+5=15Ԫ
- ��2�죺��15Ԫ��ɱ�3����Ʒ���������4��������15-3+3+4=19Ԫ
- ��3�죺��19Ԫ��ɱ�2����Ʒ���������3��������19-2+2+3=22Ԫ
- ������5+4+3=12

��һ�ֿ��ܵĲ��ԣ�
- ��1�죺��ɱ�2����Ʒ������3��������11Ԫ
- ��2�죺��ɱ�3����Ʒ������4��������12Ԫ
- ��3�죺��ɱ�4����Ʒ������5��������13Ԫ
- ������3+4+5=12

���ֲ��Զ��ܴﵽ�������12��
*/