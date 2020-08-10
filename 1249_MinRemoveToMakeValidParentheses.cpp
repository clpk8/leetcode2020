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

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else s[i] = '*'; //pending removal
            }
        }
        //mark all in the stack as reoval
        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }
        //remove will make all the * to the end, and we need to use erase to clear all *

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};