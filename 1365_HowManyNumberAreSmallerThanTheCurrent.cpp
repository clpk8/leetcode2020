//
// Created by Chunbin lin on 7/9/20.
//

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //1, 2, 2, 3, 8
        //0, 1, 1, 3, 4
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        unordered_map<int,int> map;
        for (int i = 0; i < copy.size(); i++) {
            if (map.count(copy[i])) {
                continue;
            }
            map[copy[i]] = i;
        }
        vector<int> result;
        for (int num : nums) {
            result.push_back(map[num]);
        }
        return result;
    }
};