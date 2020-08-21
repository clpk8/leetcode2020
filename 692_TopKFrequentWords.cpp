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

// my own
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter; // word:freq
        for (const auto& word: words) {
            counter[word]++;
        }

        auto comp = [&](const pair<int, string>& p1, const pair<int, string>& p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            else return p1.second < p2.second;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (const auto &e : counter) {
            pq.push(make_pair(e.second, e.first));
            if (pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};