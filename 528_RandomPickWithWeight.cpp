//
// Created by Chunbin lin on 6/5/20.
//

class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        for (auto n : w) {
            prefixSums.push_back(n + (prefixSums.empty() ? 0 : prefixSums.back()));
        }
    }

    int pickIndex() {
        auto target = rand() % prefixSums.back();
        //run a linear search
        for (int i = 0; i < prefixSums.size(); i++) {
            if (target < prefixSums[i])
                return i;
        }
        return prefixSums.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

//Faster binary search log n

class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        for (auto n : w) {
            prefixSums.push_back(n + (prefixSums.empty() ? 0 : prefixSums.back()));
        }
    }

    int pickIndex() {
        auto target = rand() % prefixSums.back();
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */