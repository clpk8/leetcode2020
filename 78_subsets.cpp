//
// Created by Chunbin lin on 5/25/20.
//

//O(N * 2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        for (int i = 0; i <= nums.size(); i++) {
            generateSubsets(nums, i, 0, cur, result);
        }
        return result;
    }
private:
    //DFS
    //n : size of each subset array, 0, 1, 2, 3
    //s: index
    void generateSubsets(const vector<int>& nums, int n, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = s; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            generateSubsets(nums, n, i+1, cur, ans);
            cur.pop_back();
        }
    }
};