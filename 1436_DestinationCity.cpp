//
// Created by Chunbin lin on 6/1/20.
//

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> degrees;
        for (auto& e: paths) {
            degrees[e[0]] += 1;
            degrees[e[1]] += 0;
        }
        for (auto it : degrees) {
            if (it.second == 0) return it.first;
        }
        return "";
    }
};