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


//Union Find sol

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
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFindSet s(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) s.Union(i, j);
            }
        }

        unordered_set<int> circles;
        for (int i = 0; i < n; i++)
            circles.insert(s.Find(i));
        return circles.size();
    }
};