//
// Created by Chunbin lin on 8/10/20.
//

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0) return 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j, n, m));
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        //bound check
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;

        //markt it to 0
        grid[x][y] = 0;
        //now, expand
        return dfs(grid, x + 1, y, n, m)
               + dfs(grid, x - 1, y, n, m)
               + dfs(grid, x, y + 1, n, m)
               + dfs(grid, x, y -1, n, m)
               + 1;
    }
};