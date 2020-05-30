//
// Created by Chunbin lin on 5/29/20.
//

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> chars;
        string res;
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (isalpha(c)) {
                res.push_back(c);
            } else if (c == '[') {
                //chear
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {
                string temp = res;
                for (int i = 0; i < nums.top() - 1; i++) {
                    res += temp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};