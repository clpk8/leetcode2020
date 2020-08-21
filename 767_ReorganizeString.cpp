//
// Created by Chunbin lin on 8/19/20.
//

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> counter;
        for (char c : S) {
            counter[c]++;
        }

        //max heap, we want the largest one to be out first
        priority_queue<pair<int, char>> pq;
        for (auto e : counter) {
            if (e.second > (S.size() + 1) / 2) return "";
            pq.push({e.second, e.first});
        }

        string res = "";
        while (pq.size() >= 2) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            res.push_back(top1.second);
            res.push_back(top2.second);
            if (--top1.first > 0) pq.push(top1);
            if (--top2.first > 0) pq.push(top2);
        }
        if (pq.size()) res.push_back(pq.top().second);
        return res;

    }
};