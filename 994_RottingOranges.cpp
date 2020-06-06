//
// Created by Chunbin lin on 6/5/20.
//

//BFS with queue

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.emplace(i, j);
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int days = 0;
        while (!q.empty() && fresh != 0) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto dir : dirs) {
                    int dx = x + dir.front();
                    int dy = y + dir.back();
                    if (dx < 0 || dx >= m || dy < 0 || dy >= n || grid[dx][dy] != 1)
                        continue;
                    fresh--;
                    grid[dx][dy] = 2;
                    q.emplace(dx, dy);
                }
            }
            days++;
        }
        return fresh ? -1 : days;
    }
};