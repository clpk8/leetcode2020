//
// Created by Chunbin lin on 8/15/20.
//

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2) {return i1.front() < i2.front();};
        sort(intervals.begin(), intervals.end(), comp);

        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[pre].back() > intervals[i].front()) {
                return false;
            } else {
                pre = i;
            }
        }
        return true;
    }
};