//
// Created by Chunbin lin on 8/15/20.
//

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all;
        for (const auto intervals : schedule) {
            all.insert(all.end(), intervals.begin(), intervals.end());
        }
        auto comp = [](Interval& a, Interval& b){return a.start < b.start;};
        sort(all.begin(), all.end(), comp);
        vector<Interval> ans;
        //virtual merge
        int end = all.front().end;
        for (const auto& busy : all) {
            if (busy.start > end)
                ans.emplace_back(end, busy.start); //found a gap
            end = max(end, busy.end); //update end
        }
        return ans;
    }
};