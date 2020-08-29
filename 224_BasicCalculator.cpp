//
// Created by Chunbin lin on 8/24/20.
//

class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = 10 * num + (s[i++] - '0');
                }
                res += sign * num;
                --i;
            } else if ( c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};