//
// Created by Chunbin lin on 8/9/20.
//

class Solution {
public:


    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>> q;
        //-1 means unvisited
        vector<vector<int>> dis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
            }
        }

        //now BFS
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto dir : dirs) {
                int x = p.first + dir[0];
                int y = p.second + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == -1) {
                    q.emplace(x, y);
                    dis[x][y] = dis[p.first][p.second] + 1;
                }
            }
        }
        return dis;
    }
};