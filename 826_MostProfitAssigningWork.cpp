//
// Created by Chunbin lin on 8/21/20.
//

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < difficulty.size(); i++) {
            pairs.emplace_back(difficulty[i], profit[i]);
        }
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) return p2.second > p1.second;
            return p1.first < p2.first;
        };
        sort(worker.begin(), worker.end());
        sort(pairs.begin(), pairs.end(), comp);
        int i = 0, maxProfit = 0, ans = 0;

        for (int skill : worker) {
            while (i < difficulty.size() && skill >= pairs[i].first) {
                maxProfit = max(maxProfit, pairs[i].second);
                i++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};