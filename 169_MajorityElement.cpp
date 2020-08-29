//
// Created by Chunbin lin on 8/24/20.
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        for (auto e : counter) {
            if (e.second > nums.size()/2) return e.first;
        }
        return -1;
    }
};