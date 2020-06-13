//
// Created by Chunbin lin on 6/12/20.
//

class Solution {
private:
    int floodFill(vector <vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return 1 + floodFill(grid, x + 1, y)
               + floodFill(grid, x - 1, y)
               + floodFill(grid, x, y + 1)
               + floodFill(grid, x, y - 1);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        //fill corner
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i * j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
                    floodFill(grid, i, j);
            }
        }

        //coutn
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                res += floodFill(grid, i, j);
            }
        }
        return res;
    }
};