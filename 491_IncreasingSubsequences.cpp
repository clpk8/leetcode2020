//
// Created by Chunbin lin on 5/30/20.
//

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //back tracking dfs

        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, seq, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
        if (seq.size() > 1) res.push_back(seq);

        unordered_set<int> set;

        for (int i = pos; i < nums.size(); i++) {
            if ((seq.empty() || nums[i] >= seq.back()) && !set.count(nums[i])) {
                seq.push_back(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
                set.insert(nums[i]);
            }
        }
    }
};