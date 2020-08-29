//
// Created by Chunbin lin on 8/28/20.
//

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(dfs(matrix, dp, j, i, m, n), ans);
            }
        }
        return ans;
    }


    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y, int m, int n) {
        if (dp[y][x] != -1) return dp[y][x];

        //now mark it as processed
        dp[y][x] = 1;
        for (auto dir : dirs) {
            int tx = dir.front() + x;
            int ty = dir.back() + y;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || matrix[ty][tx] <= matrix[y][x])
                //we want it in boundry and also increasing
                continue;
            dp[y][x] = max(dp[y][x], 1 + dfs(matrix, dp, tx, ty, m, n));
        }
        return dp[y][x];

    }
};