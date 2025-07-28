#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	ll M;
	// �ȶ� k �� M
	cin >> k >> M;
	// ���յ���һ��ĩβ�Ļ��з���������� getline ��ֱ�Ӷ�������
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// �����е� cost �� profit
	string cost_line, profit_line;
	getline(cin, cost_line);
	getline(cin, profit_line);

	// �����ɱ����������� vector
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
	// �� (cost, profit) �Էŵ�һ�𣬲��� cost ��������
	vector<pair<ll, ll>> items(n);
	for (int i = 0; i < n; i++) {
		items[i] = {cost[i], profit[i]};
	}
	sort(items.begin(), items.end(),
	[](auto & a, auto & b) {
		return a.first < b.first;
	});

	// ���ѣ��浱ǰ��������������Ʒ������
	priority_queue<ll> pq;
	ll capital = M;
	int idx = 0;

	// ����� k ��
	for (int day = 0; day < k; day++) {
		// ������ cost <= capital ����Ʒ�����ƽ���
		while (idx < n && items[idx].first <= capital) {
			pq.push(items[idx].second);
			idx++;
		}
		if (pq.empty())
			break;  // �����κ���Ʒ����ǰ�˳�

		// ȡ���������Ǽ���Ʒ
		capital += pq.top();
		pq.pop();
	}

	// ���������� = ��ǰ�ʽ� - ��ʼ�ʽ�
	cout << (capital - M) << "\n";
	return 0;
}



/*
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

