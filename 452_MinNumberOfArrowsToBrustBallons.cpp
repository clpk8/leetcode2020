//
// Created by Chunbin lin on 8/15/20.
//

//Sort by back()
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return a.back() < b.back();});
        int right = intervals.front().back();
        int ans = 1;
        for (const auto& interval: intervals) {
            if (interval.front() > right) {
                right = interval.back();
                ans++;
            }
        }
        return ans;
    }
};