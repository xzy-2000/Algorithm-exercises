#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main() {
	string cost_line, need_line;
	getline(cin, cost_line);
	getline(cin, need_line);

	// �������ص�������
	vector<int> counties;
	stringstream ss1(cost_line);
	int temp;
	while (ss1 >> temp) {
		counties.push_back(temp);
	}

	// ���������������ö��б�ʾ�Ŷ�
	queue<int> deputies;
	stringstream ss2(need_line);
	while (ss2 >> temp) {
		deputies.push(temp);
	}

	int total_deputies = deputies.size(); // ��¼�ܸ�����

	// ģ����ʳ���Ź���
	for (int county_idx = 0; county_idx < counties.size(); county_idx++) {
		int k = counties[county_idx]; // ��ǰ�س��ӵ�������

		if (deputies.empty()) {
			break; // û�и����ˣ�����
		}

		int current_need = deputies.front();

		if (k == current_need) {
			// ����1��k���ڵ�ǰ�������󣬸�����ȡ���뿪
			deputies.pop();
		} else if (k > current_need) {
			// ����2��k���ڵ�ǰ��������Ѱ����һ������ĸ������
			vector<int> all_deputies;

			// �����������и�������浽������
			while (!deputies.empty()) {
				all_deputies.push_back(deputies.front());
				deputies.pop();
			}

			if (all_deputies.empty())
				continue;

			int first_need = all_deputies[0]; // ��1����������
			int remaining = k - first_need;   // �����1��������ʣ�������
			int selected_idx = -1;           // ѡ�еĵ�i����������

			// �ӵ�2��������ʼ��Ѱ�������1������һ������ĸ���
			for (int i = 1; i < all_deputies.size(); i++) {
				if (all_deputies[i] <= remaining) {
					selected_idx = i;
					remaining -= all_deputies[i];
					break; // �ҵ���һ�����������ľ�ֹͣ
				}
			}

			if (selected_idx == -1) {
				// û�ҵ���һ������ĸ�����ֻ�����1������
				// ��2�����Ժ�ĸ����������
				for (int i = 1; i < all_deputies.size(); i++) {
					deputies.push(all_deputies[i]);
				}
			} else {
				// �ҵ��˵�i����������1���͵�i��������ȡ��ʳ
				// ��2����(i-1)�������Ƶ���β
				// ��(i+1)�����Ժ�ĸ�������ԭ˳��

				// �ȼ����(i+1)�����Ժ�ĸ���
				for (int j = selected_idx + 1; j < all_deputies.size(); j++) {
					deputies.push(all_deputies[j]);
				}

				// �ټ����2����(i-1)���������Ƶ���β��
				for (int j = 1; j < selected_idx; j++) {
					deputies.push(all_deputies[j]);
				}
			}
		} else {
			// ����3��kС�ڵ�ǰ�������󣬸����Ƶ���β
			deputies.pop();
			deputies.push(current_need);
		}
	}

	// ������ղ����쵽��ʳ�ĸ�������
	cout << deputies.size() << endl;

	return 0;
}

/*
ʾ��1��
���룺
5 3 2
4 3 2 1
�����
0

���룺
5 3 2
4 2 3 1
�����
1
*/