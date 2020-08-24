//
// Created by Chunbin lin on 8/23/20.
//

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        //build graph
        for (const auto& p: prerequisites) {
            graph[p.back()].push_back(p.front());
        }

        //states: 0 = unknown, 1 == visiting, 2 == visited
        vector<int> v(numCourses, 0);

        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, v, ans, graph)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:


    bool dfs(int cur, vector<int>& v, vector<int>& ans, vector<vector<int>>& graph) {
        if (v[cur] == 1) return true; // 1 is visiting, so circle found
        if (v[cur] == 2) return false; // 2 is visited, do not cont

        //not visited
        v[cur] = 1; //we are visiting
        for (const auto t : graph[cur]) {
            if (dfs(t, v, ans, graph)) return true;
        }
        v[cur] = 2; // mark as visited
        ans.push_back(cur);
        return false;
    }
};