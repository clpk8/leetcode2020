//
// Created by Chunbin lin on 8/19/20.
//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](const vector<int> &p1, const vector<int> &p2) {
            int dis1 = p1.front() * p1.front() + p1.back() * p1.back();
            int dis2 = p2.front() * p2.front() + p2.back() * p2.back();

            return sqrt(dis1) < sqrt(dis2);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto point : points) {
            pq.push(point);
            if (pq.size() > K) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};