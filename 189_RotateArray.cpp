//
// Created by Chunbin lin on 8/28/20.
//

//using space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) return;
        if (k > nums.size()) k -= nums.size();
        vector<int> n;
        n.insert(n.begin(), nums.begin() + nums.size() - k, nums.end());
        n.insert(n.end(), nums.begin(), nums.end() - k);
        nums = n;
    }
};

//best 01 space trick
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());

        if (k > nums.size()) k-= nums.size();
        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};