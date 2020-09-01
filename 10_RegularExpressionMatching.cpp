//
// Created by Chunbin lin on 8/31/20.
//


//Brute force
// O((T+P) 2^T)
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if (p.size() >= 2 && p[1] == '*') {
            // take care of aab match c*a*b case, if we have *, we eight check if rest of the string will work
            // or first march and second will also match
            return (isMatch(s, p.substr(2))) || (first_match && isMatch(s.substr(1), p));
        } else {
            // if not *, we bascially return first match and rest also match
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

//better ON time and O(S * P) space

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];

    }
};