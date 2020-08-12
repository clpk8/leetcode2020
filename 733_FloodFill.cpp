//
// Created by Chunbin lin on 8/11/20.
//

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        if (n == 0) return image;
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
            dfs(sr, sc, n, m, image, oldColor, newColor);
        return image;
    }
private:
    void dfs(int sr, int sc, int n, int m, vector<vector<int>>& image, int oldColor, int newColor) {
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != oldColor)
            return;
        image[sr][sc] = newColor;
        dfs(sr + 1, sc, n, m, image, oldColor, newColor);
        dfs(sr - 1, sc, n, m, image, oldColor, newColor);
        dfs(sr, sc + 1, n, m, image, oldColor, newColor);
        dfs(sr, sc - 1, n, m, image, oldColor, newColor);
    }
};