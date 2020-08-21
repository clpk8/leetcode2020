//
// Created by Chunbin lin on 8/19/20.
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter; // num : freq
        for (int num : nums) {
            counter[num]++;
        }

        auto comp = [&](const pair<int, int> p1, const pair<int, int> p2) {
            return p1.second > p2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (auto e : counter) {
            pq.push(make_pair(e.first, e.second));
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};