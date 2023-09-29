/* https://leetcode.com/problems/rotting-oranges/description/ 
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */

class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt = 0; // keep count of the elapsed time until no cell has a fresh orange

    bool inside(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    void bfs(int i,int j, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        // Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        // Perform BFS to simulate the rotting process
        while (!q.empty()) {    
            int q_size = q.size(); // Get the current level size
            bool level_rotted = false; // Flag to check if any oranges rotted at this level
            
            for (int t = 0; t < q_size; t++) {
                pair<int, int> cur = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int newx = cur.first + dx[k];
                    int newy = cur.second + dy[k];
                    
                    if (inside(newx, newy) && grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                        level_rotted = true; // Mark that an orange rotted at this level
                    }
                }
            }
            
            if (level_rotted) {
                cnt++; // Increment the time unit only if any oranges rotted at this level
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        bfs(0,0,grid);
        // Check if there are any remaining fresh oranges in the final state
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return cnt;
    }
};
