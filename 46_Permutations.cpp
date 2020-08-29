//
// Created by Chunbin lin on 8/26/20.
//
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, path, used, 0, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<int>& path, vector<int>& used, int d, vector<vector<int>>& ans) {
        if (nums.size() == d) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;;
            used[i] = 1;
            path.push_back(nums[i]);
            dfs(nums, path, used, d + 1, ans);
            used[i] = 0;
            path.pop_back();
        }
    }
};