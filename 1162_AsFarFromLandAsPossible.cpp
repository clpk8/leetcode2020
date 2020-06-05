//
// Created by Chunbin lin on 6/4/20.
//

//DFS slow
//Runtime: O(m * n * n), where m is the number of land cells.
//Memory: O(n * n) for the recursion.
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int mx = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    dfs(grid, i, j);
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 1) mx = max(mx, grid[i][j] - 1);
            }
        }
        return mx;
    }
private:
    void dfs(vector<vector<int>>& g, int i, int j, int dist = 1) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || (g[i][j] != 0 && g[i][j] <= dist)) return;
        g[i][j] = dist;
        dfs(g, i + 1, j, dist + 1);
        dfs(g, i - 1, j, dist + 1);
        dfs(g, i, j + 1, dist + 1);
        dfs(g, i, j - 1, dist + 1);
    }
};

//BFS Faster
//Runtime: O(n * n). We process an individual cell only once (or twice).
//Memory: O(n) for the queue.
class Solution {
public:
    int maxDistance(vector<vector<int>>& g, int steps = 0) {
        queue<pair<int, int>> q, q1;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 1)
                    q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
        while (!q.empty()) {
            ++steps;
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
                    g[i][j] = steps;
                    q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
                }
            }
            swap(q1, q);
        }
        return steps == 1 ? -1 : steps - 1;
    }
};
