//
// Created by Chunbin lin on 5/22/20.
//

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return a.front() < b.front();});
        //min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto interval : intervals) {
            if (!pq.empty() && pq.top() <= interval.front())
                pq.pop();
            pq.push(interval.back());
        }
        return pq.size();
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> map;
        for (auto i : intervals) {
            map[i[0]]++;
            map[i[1]]--;
        }
        int rooms = 0, res = 0;
        for (auto it : map) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};
