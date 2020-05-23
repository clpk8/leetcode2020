//
// Created by Chunbin lin on 5/22/20.
//


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //use map to put them
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        for (const auto& it : count) {
            pq.push(it);
            if (pq.size() > k) pq.pop();

        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
private:
    struct compare {
        bool operator() ( pair<string, int>& p, pair<string, int>& q) {
            return p.second > q.second || (p.second == q.second && p.first < q.first);
        }
    };
};