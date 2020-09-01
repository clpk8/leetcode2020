//
// Created by Chunbin lin on 8/30/20.
//

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
