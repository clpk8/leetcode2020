//
// Created by Chunbin lin on 8/22/20.
//

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return helper(maze, start.front(), start.back(), destination);
    }
private:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool helper(vector<vector<int>>& maze, int i, int j, vector<int>& destination) {
        if (i == destination.front() && j == destination.back()) return true;
        bool ans = false;
        int m = maze.size(), n = maze[0].size();
        maze[i][j] = -1;
        for (auto dir : dirs) {
            int x = i, y = j;
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                x += dir[0];
                y += dir[1];
            }

            //now we either hit a wall or boundry
            x -= dir[0];
            y -= dir[1];
            // check if we visited it before
            if (maze[x][y] != -1)
                ans |= helper(maze, x, y, destination);
        }
        return ans;
    }
};

//BFS

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return true;
        int m = maze.size(),  n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == destination.front() && t.second == destination.back()) return true;
            for (auto dir : dirs) {
                int x = t.first, y = t.second;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0]; y += dir[1];
                }
                x -= dir[0];
                y -= dir[1];
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;

    }
};