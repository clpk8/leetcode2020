//
// Created by Chunbin lin on 8/23/20.
//

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto &pair : tickets) {
            trips[pair.front()].push_back(pair.back());
        }

        //sort
        for (auto& pair : trips) {
            sort(pair.second.begin(), pair.second.end());
        }

        const string start = "JFK";
        visit(start);
        return vector<string>(route.crbegin(), route.crend());
    }

private:
    unordered_map<string, deque<string>> trips;
    vector<string> route;

    void visit(string src) {
        auto& dests = trips[src];
        while (!dests.empty()) {
            const string dest = dests.front();
            dests.pop_front();
            visit(dest);
        }

        route.push_back(src);
    }
};