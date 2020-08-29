//
// Created by Chunbin lin on 8/27/20.
//

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res, starts;
        unordered_map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
            starts.push_back(intervals[i][0]);
        }

        sort(starts.rbegin(), starts.rend());
        for (auto interval : intervals) {
            int i = 0;
            for (; i < starts.size(); ++i) {
                if (starts[i] < interval[1]) break;
            }
            res.push_back((i > 0) ? m[starts[i - 1]] : -1);
        }
        return res;
    }
};