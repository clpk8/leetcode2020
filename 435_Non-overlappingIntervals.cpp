//
// Created by Chunbin lin on 8/15/20.
//

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2) {return i1.front() < i2.front();};
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].front() < intervals[pre].back()) {
                res++;
                if (intervals[i].back() < intervals[pre].back()) pre = i;
            }
            else pre = i;
        }
        return res;
    }
};