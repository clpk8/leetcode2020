//
// Created by Chunbin lin on 6/14/20.
//

//DFS with coloring and prunning

class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> graph;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph.clear();
        for (const auto &e : flights) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }
        vector<int> visited(n, 0);
        visited[src] = 1;
        int ans = INT_MAX;
        dfs(src, dst, K + 1, 0, visited, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(int src, int dst, int k, int cost, vector<int>& visited, int&ans) {
        if (src == dst) {
            //got there
            ans = cost;
            return;
        }

        if (k == 0) return; // no more stops
        for (const auto &p : graph[src]) {
            if (visited[p.first]) continue; //dont need to visit same city twice
            if (cost + p.second > ans) continue; //we alreay have better choice
            visited[p.first] = 1; //mark it visited
            dfs(p.first, dst, k - 1, cost + p.second, visited, ans);
            visited[p.first] = 0;

        }
    }
};


//BFS prunning
class Solution {
private:
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        graph.clear();
        for (const auto &e : flights) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }

        int ans = INT_MAX;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front().first;
                int cost = q.front().second;
                q.pop();
                if (curr == dst)
                    ans = min(ans, cost);
                for (const auto& p : graph[curr]) {
                    if (cost + p.second > ans) continue; // prunning
                    q.push({p.first, cost + p.second});
                }
            }
            if (steps++ > K) break;
        }
        return ans == INT_MAX ? -1 : ans;

    }

};