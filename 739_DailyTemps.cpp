//
// Created by Chunbin lin on 8/8/20.
//

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int n = T.size();
        stack<int> s;
        vector<int> ans(n);
        // from back to front, stack keep track of the indices
        // pop off the smaller element so sta k is monotinic
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && T[s.top()] <= T[i])
                s.pop();
            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return ans;
    }
};