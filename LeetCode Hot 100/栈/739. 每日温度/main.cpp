#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> dailyTemperatures(vector<int> &temperatures) {
			stack<int> st; // µİÔöÕ»
			vector<int> result(temperatures.size(), 0);
			for (int i = 0; i < temperatures.size(); i++) {
				while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
					result[st.top()] = i - st.top();
					st.pop();
				}
				st.push(i);
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> Temp = solution.dailyTemperatures(temperatures);
	for (int i = 0; i < Temp.size(); i++) {
		cout << Temp[i] << " ";
	}
	return 0;
}
/*
[73, 74, 75, 71, 69, 72, 76, 73]
[1, 1, 4, 2, 1, 1, 0, 0]¡£
*/