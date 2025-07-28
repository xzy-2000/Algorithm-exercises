#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main() {
	string cost_line, need_line;
	getline(cin, cost_line);
	getline(cin, need_line);

	// 解析各县的粮车数
	vector<int> counties;
	stringstream ss1(cost_line);
	int temp;
	while (ss1 >> temp) {
		counties.push_back(temp);
	}

	// 解析副将的需求，用队列表示排队
	queue<int> deputies;
	stringstream ss2(need_line);
	while (ss2 >> temp) {
		deputies.push(temp);
	}

	int total_deputies = deputies.size(); // 记录总副将数

	// 模拟粮食发放过程
	for (int county_idx = 0; county_idx < counties.size(); county_idx++) {
		int k = counties[county_idx]; // 当前县车队的粮车数

		if (deputies.empty()) {
			break; // 没有副将了，结束
		}

		int current_need = deputies.front();

		if (k == current_need) {
			// 规则1：k等于当前副将需求，副将领取后离开
			deputies.pop();
		} else if (k > current_need) {
			// 规则2：k大于当前副将需求，寻找能一起满足的副将组合
			vector<int> all_deputies;

			// 将队列中所有副将需求存到数组中
			while (!deputies.empty()) {
				all_deputies.push_back(deputies.front());
				deputies.pop();
			}

			if (all_deputies.empty())
				continue;

			int first_need = all_deputies[0]; // 第1个副将需求
			int remaining = k - first_need;   // 满足第1个副将后剩余的粮车
			int selected_idx = -1;           // 选中的第i个副将索引

			// 从第2个副将开始，寻找能与第1个副将一起满足的副将
			for (int i = 1; i < all_deputies.size(); i++) {
				if (all_deputies[i] <= remaining) {
					selected_idx = i;
					remaining -= all_deputies[i];
					break; // 找到第一个符合条件的就停止
				}
			}

			if (selected_idx == -1) {
				// 没找到能一起满足的副将，只满足第1个副将
				// 第2个及以后的副将重新入队
				for (int i = 1; i < all_deputies.size(); i++) {
					deputies.push(all_deputies[i]);
				}
			} else {
				// 找到了第i个副将，第1个和第i个副将领取粮食
				// 第2到第(i-1)个副将移到队尾
				// 第(i+1)个及以后的副将保持原顺序

				// 先加入第(i+1)个及以后的副将
				for (int j = selected_idx + 1; j < all_deputies.size(); j++) {
					deputies.push(all_deputies[j]);
				}

				// 再加入第2到第(i-1)个副将（移到队尾）
				for (int j = 1; j < selected_idx; j++) {
					deputies.push(all_deputies[j]);
				}
			}
		} else {
			// 规则3：k小于当前副将需求，副将移到队尾
			deputies.pop();
			deputies.push(current_need);
		}
	}

	// 输出最终不能领到粮食的副将数量
	cout << deputies.size() << endl;

	return 0;
}

/*
示例1：
输入：
5 3 2
4 3 2 1
输出：
0

输入：
5 3 2
4 2 3 1
输出：
1
*/