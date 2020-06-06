//
// Created by Chunbin lin on 6/5/20.
//

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int close = count(s.begin(), s.end(), ')');
        int open = 0;
        string ans;

        for (char c : s) {
            if (c == '('){
                if (open == close) continue;
                open++;
            }  else if (c == ')') {
                close--;
                if (open == 0) continue;
                open--;
            }
            ans +=c;
        }
        return ans;
    }
};