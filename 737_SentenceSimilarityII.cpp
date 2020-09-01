//
// Created by Chunbin lin on 8/30/20.
//



//Time complexity: O(|Pairs| * |words1|)
//
//Space complexity: O(|Pairs|)
class Solution {
public:
    bool areSentencesSimilarTwo(vector <string> &words1, vector <string> &words2, vector <vector<string>> &pairs) {
        if (words1.size() != words2.size()) return false;
        //build graph
        for (auto pair : pairs) {
            graph_[pair.front()].insert(pair.back());
            graph_[pair.back()].insert(pair.front());
        }

        //visited set
        unordered_set <string> visited;
        for (int i = 0; i < words1.size(); i++) {
            visited.clear();
            if (!dfs(words1[i], words2[i], visited)) return false;
        }
        return true;
    }

private:
    unordered_map <string, unordered_set<string>> graph_;

    bool dfs(string src, string dest, unordered_set <string> &visited) {
        if (src == dest) return true;
        visited.insert(src);
        for (auto &next : graph_[src]) {
            if (visited.count(next)) continue;
            if (dfs(next, dest, visited)) return true;
        }
        return false;
    }
};

//Better Union find

//
// Created by Chunbin lin on 8/30/20.
//

//Basic implementation of union find
// Find will be about O(1) ave, because of compression
// Union will also be about o1

//need to do path compression in find and union by rank in union.
//soace On
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


// Time complexity: O(|Pairs| + |words1|)
//
//Space complexity: O(|Pairs|)
class Solution {
public:
    bool areSentencesSimilarTwo(vector <string> &words1, vector <string> &words2, vector <vector<string>> &pairs) {

        if (words1.size() != words2.size()) return false;
        UnionFindSet s(pairs.size() * 2);
        unordered_map<string, int> indicies; //mapping
        //build frost
        for (int i = 0; i < pairs.size(); i++) {
            int u = getIndex(pairs[i].front(), indicies, true);
            int v = getIndex(pairs[i].back(), indicies, true);
            s.Union(u, v);
        }

        //now check
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) continue;
            int u = getIndex(words1[i], indicies);
            int v = getIndex(words2[i], indicies);
            if (u < 0 || v < 0) return false; //no even in our union find set
            if (s.Find(u) != s.Find(v)) return false;
        }

        return true;


    }

private:
    int getIndex(const string &word, unordered_map<string, int> &indicies, bool create = false) {
        if (indicies.count(word)) {
            auto s = indicies[word];
            cout << s;
            return s; //return indec
        } else {
            //create index
            if (!create) return INT_MIN; // not found
            int index = indicies.size();
            indicies[word] = index;
            return index; // create and return
        }
    }
};