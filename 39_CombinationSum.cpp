//
// Created by Chunbin lin on 8/13/20.
//

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        //sort candidates so we know it is in increasing order
        //otherwise will not wokr
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans, curr, 0, target, candidates);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& curr, int index, int target, vector<int> candidates) {
        if (target == 0) {
            //end case
            ans.push_back(curr);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break; //VREY important, we don't need to continue
            curr.push_back(candidates[i]);
            dfs(ans, curr, i, target - candidates[i], candidates);
            curr.pop_back(); //backtrack
        }
    }
};