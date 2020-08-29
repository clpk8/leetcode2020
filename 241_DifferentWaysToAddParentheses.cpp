//
// Created by Chunbin lin on 8/24/20.
//

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (mem.count(input)) return mem[input];

        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            char op = input[i];
            if (op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);

                //get left and right
                const vector<int>& l = diffWaysToCompute(left);
                const vector<int>& r = diffWaysToCompute(right);

                for (int a : l) {
                    for (int b : r) {
                        ans.push_back(calculation(a, b, op));
                    }
                }
            }
        }

        if (ans.empty()) ans.push_back(stoi(input)); // just single chars
        mem[input] = ans;
        return ans;
    }

private:
    unordered_map<string, vector<int>> mem;

    int calculation(int l, int r, char op) {
        switch (op) {
            case '+': return l + r;
            case '-': return l - r;
            case '*': return l * r;
            default:
                return -1;
        }
    }

};