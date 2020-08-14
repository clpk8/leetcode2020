//
// Created by Chunbin lin on 8/13/20.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a','b','c'};
        d[3] = {'d','e','f'};
        d[4] = {'g','h','i'};
        d[5] = {'j','k','l'};
        d[6] = {'m','n','o'};
        d[7] = {'p','q','r','s'};
        d[8] = {'t','u','v'};
        d[9] = {'w','x','y','z'};
        string curr;
        vector<string> ans;
        dfs(digits, d, 0, ans, curr);
        return ans;
    }
    void dfs(string digits, vector<vector<char>> d, int currIndex, vector<string>& ans, string curr) {
        // when index is the size, we reach the end
        if (currIndex == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for (char c : d[digits[currIndex] - '0']) {
            // for char in one of the vector<char>
            curr.push_back(c);
            dfs(digits, d, currIndex + 1, ans, curr);
            curr.pop_back(); //backtrack
        }
    }
};