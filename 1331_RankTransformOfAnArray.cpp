//
// Created by Chunbin lin on 6/3/20.
//

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> map;
        int dif = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (map.count(arr[i])) {
                dif++;
                continue;
            }
            map[arr[i]] = i - dif;
        }

        vector<int> result;
        for (int i = 0; i < copy.size(); i++) {
            result.push_back(map[copy[i]]+1);
        }
        return result;

    }
};