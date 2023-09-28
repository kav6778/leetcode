/* https://leetcode.com/problems/number-of-islands/description/
 */

class Solution {
public:
    int dx[8] = {1, 0, -1, 0};
    int dy[8] = {0, 1, 0, -1};

    bool inside(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }   

    void bfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newx = cur.first + dx[k];
                int newy = cur.second + dy[k];

                if (inside(newx, newy, n, m) && grid[newx][newy] == '1' && !visited[newx][newy]) {
                    visited[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;  // Initialize island count

        vector<vector<bool>> visited(n, vector<bool>(m, 0));
      
        //The BFS continues until there are no more unvisited land cells connected to the initial cell (row, col)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;  // Found a new island
                    bfs(i, j, n, m, grid, visited);
                }
            }
        }
        return cnt;
    }
};
