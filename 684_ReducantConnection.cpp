//
// Created by Chunbin lin on 8/30/20.
//

//DFS
// Time Complexity: O(n^2)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            unordered_set<int> visited;
            if (hasPath(u, v, graph, visited))
                return edge; //first circle
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool hasPath(int curr,
                 int goal,
                 const unordered_map<int, vector<int>>& graph,
                 unordered_set<int>& visited) {
        if (curr == goal) return true;
        visited.insert(curr);
        if (!graph.count(curr) || !graph.count(goal)) return false;
        for (int next : graph.at(curr)) {
            if (visited.count(next)) continue;
            if (hasPath(next, goal, graph, visited)) return true;
        }
        return false;
    }
};


//Union Find

class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);
        parents_ = vector<int>(n + 1, 0);
        for (int i = 0; i < parents_.size(); i++)
            parents_[i] = i;
    }

    // merge sets that contains u and v.
    // return true if merged, false if u and v already in a same set
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;

        //merge low rank tree into high rank
        if (ranks_[pv] < ranks_[pu])
            parents_[pv] = pu;
        else if (ranks_[pu] < ranks_[pv])
            parents_[pu] = pv;
        else {
            //same rank
            parents_[pv] = pu;
            ranks_[pu] += 1;
        }
        return true;
    }

    // Get root
    int Find(int u) {

        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet s(edges.size());
        for (auto edge : edges) {
            if (!s.Union(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
