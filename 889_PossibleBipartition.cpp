//
// Created by Chunbin lin on 5/27/20.
//

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N);
        for (const auto &d : dislikes) {
            graph[d[0]-1].push_back(d[1]-1);
            graph[d[1]-1].push_back(d[0]-1);
        }

        colors = vector<int>(N, 0); // 0: uncolored, 1: red, -1:blue
        for (int i = 0; i < N; i++) {
            if (colors[i] == 0 && !dfs(i, 1)) return false;
        }
        return true;

    }
private:
    vector<vector<int>> graph;
    vector<int> colors;
    bool dfs(int cur, int color) {
        //mark current color
        colors[cur] = color;
        for (int nxt : graph[cur]) {
            if (colors[nxt] == color) {
                //this is false, since color has to be red, blue, red, blue
                return false;
            }
            if (colors[nxt] == 0 && !dfs(nxt, -color)) {
                //now recursive call and toggle color
                return false;
            }
        }
        return true;
    }
};


//BFS

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(N);
        for (const auto &d : dislikes) {
            g[d[0]-1].push_back(d[1]-1);
            g[d[1]-1].push_back(d[0]-1);
        }

        queue<int> q;
        vector<int> colors(N, 0);

        for (int i = 0; i < N; i++) {
            if (colors[i] != 0) continue;

            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nxt : g[cur]) {
                    if (colors[nxt] == colors[cur]) return false;
                    if (colors[nxt] != 0) continue;
                    colors[nxt] = -colors[cur];
                    q.push(nxt);
                }
            }
        }
        return true;
    }

};