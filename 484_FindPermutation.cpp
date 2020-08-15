//
// Created by Chunbin lin on 8/15/20.
//

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans(s.size() + 1);
        stack<int> stk;
        int j = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i-1] == 'I') {
                stk.push(i);
                while (!stk.empty()) {
                    ans[j] = stk.top();
                    stk.pop();
                    j++;
                }
            } else {
                stk.push(i);
            }
        }
        stk.push(s.size() + 1);
        while (!stk.empty()) {
            ans[j++] = stk.top();
            stk.pop();
        }
        return ans;
    }
};