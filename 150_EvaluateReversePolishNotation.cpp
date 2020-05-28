//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //stack problem
        stack<int> values;
        for (string token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                //digit
                values.push(stoi(token));
            } else {
                //it has to be operator
                int op1 = values.top();
                values.pop();
                int op2 = values.top();
                values.pop();

                //do the math
                if (token == "+") {
                    values.push(op2 + op1);
                } else if (token == "-") {
                    values.push(op2 - op1);
                } else if (token == "*") {
                    values.push(op2 * op1);
                } else if (token == "/") {
                    values.push(op2 / op1);
                }
            }

        }
        return values.top();
    }
};