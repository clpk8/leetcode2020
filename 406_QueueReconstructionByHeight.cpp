//
// Created by Chunbin lin on 6/6/20.
//

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
        { return p1.front() > p2.front() || (p1.front() == p2.front() && p1.back() < p2.back()); };

        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (auto &p : people) {
            res.insert(res.begin() + p.back(), p);
        }
        return res;


    }
};