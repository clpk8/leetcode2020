//
// Created by Chunbin lin on 8/15/20.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        auto comp = [](const vector<int>& i1, const vector<int>& i2) {return i1.front() < i2.front();};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (const auto& interval : intervals) {
            if (ans.empty() || interval.front() > ans.back().back()) {
                ans.push_back(interval);
            } else {
                ans.back().back() = max(ans.back().back(), interval.back());
            }
        }
        return ans;
    }
};