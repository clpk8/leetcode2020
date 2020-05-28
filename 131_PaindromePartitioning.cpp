//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }
    void generatePalindrome(int index, vector<vector<string>>& result, vector<string>& cur, string& s) {
        if (index == s.size()) {
            result.push_back(cur);
            return;
        }

        //normal backtracking
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                cur.push_back(s.substr(index, i - index + 1));
                generatePalindrome(i + 1, result, cur, s);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> result;
        vector<string> cur;
        if (n == 0) return result;
        generatePalindrome(0, result, cur, s);
        return result;
    }

};