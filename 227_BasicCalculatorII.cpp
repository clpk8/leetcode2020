//
// Created by Chunbin lin on 8/26/20.
//

class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<char> opStack;
        bool encountered = false;;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = 10 * num + (s[i++] - '0');
                }
                numStack.push(num);
                i--;

                if (encountered) {
                    int n1 = numStack.top(); numStack.pop();
                    int n2 = numStack.top(); numStack.pop();
                    int op = opStack.top(); opStack.pop();
                    if (op == '*')
                        numStack.push(n1 * n2);
                    else
                        numStack.push(n2 / n1);
                    encountered = false;
                }
            } else if (c == '*' || c == '/') {
                encountered = true;
                opStack.push(c);
            } else if (c == '+' || c == '-') {
                opStack.push(c);
            }
        }

        int total = 0;
        while (!opStack.empty()) {
            int n1 = numStack.top(); numStack.pop();
            int op = opStack.top(); opStack.pop();
            if (op == '+')
                total += n1;
            else
                total -= n1;
        }
        total += numStack.top();
        return total;


    }
};