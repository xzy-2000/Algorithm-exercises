#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int numIslands(vector<vector<char>> &grid) {
			int result = 0;
			vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == '1' && !visited[i][j]) {
						result++;
						// dfs(grid, i, j);
						bfs(grid, visited, i, j);
					}
				}
			}
			return result;
		}

		// DFS
	private:
		typedef pair<int, int> P;
		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
		void dfs(vector<vector<char>> &grid, int x, int y) {
			// 终止条件
			if (x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1 || grid[x][y] != '1') {
				return;
			}
			grid[x][y] = '2';
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				dfs(grid, nx, ny);
			}
		}
		// BFS
		void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y) {
			queue<P> que;
			que.push({x, y});
			visited[x][y] = true;
			while (!que.empty()) {
				P p = que.front();
				que.pop();
				for (int i = 0; i < 4; i++) {
					int nx = p.first + dx[i];
					int ny = p.second + dy[i];//移动后的坐标
					if (nx < 0 || ny < 0 || nx > grid.size() - 1 || ny > grid[0].size() - 1)
						continue;
					if (!visited[nx][ny] && grid[nx][ny] == '1') {
						que.push({nx, ny});
						visited[nx][ny] = true;
					}
				}
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
	cout << solution.numIslands(grid);
	return 0;
}