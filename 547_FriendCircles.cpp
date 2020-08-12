//
// Created by Chunbin lin on 8/10/20.
//

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(M, visited, i, n);
            ans++;
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int curr, int size) {
        if (visited[curr]) return;
        //mark as visited
        visited[curr] = 1;
        //visit all friends
        for (int i = 0; i < size; i++) {
            if (M[curr][i] == 1 && !visited[i])
                dfs(M, visited, i, size);
        }
    }
};