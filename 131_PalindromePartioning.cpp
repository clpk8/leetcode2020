
//
// Created by Chunbin lin on 8/13/20.
//

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(ans, s, curr, 0);
        return ans;
    }
private:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void dfs(vector<vector<string>>& ans, string s, vector<string> curr, int index) {
        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!isPalindrome(s, index, i)) continue;
            //curretn is palindrome
            curr.push_back(s.substr(index, i - index + 1));
            dfs(ans, s, curr, i + 1);
            curr.pop_back();
        }
    }
};