//
// Created by Chunbin lin on 8/9/20.
//

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        const int n = grid.size();
        const int m = grid[0].size();
        vector<int> offset = {0, 1, 0, -1, 0};
        int nums = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    nums++;
                    //now use BFS to set all connected 1 to 0
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offset[k]; //row
                            int c = p.second + offset[k+1]; //col
                            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.emplace(r, c);
                            }
                        }
                    }
                }
            }
        }
        return nums;
    }
};

//DFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        const int n = grid.size();
        const int m = grid[0].size();

        int nums = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    nums++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return nums;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        dfs(grid, x + 1, y, n, m);
        dfs(grid, x - 1, y, n, m);
        dfs(grid, x, y + 1, n, m);
        dfs(grid, x, y - 1, n, m);
    }
};