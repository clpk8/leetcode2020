//
// Created by Chunbin lin on 8/10/20.
//

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> g(n);
        vector<int> visited(n, 0);
        for (auto edge : edges) {
            g[edge.front()].push_back(edge.back());
            g[edge.back()].push_back(edge.front());
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(g, visited, i);
            ans++;
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int curr) {
        if (visited[curr]) return;
        //mark as visited
        visited[curr] = 1;
        //visit all friends
        for (int i = 0; i < M[curr].size(); i++) {
            dfs(M, visited, M[curr][i]);
        }
    }
};