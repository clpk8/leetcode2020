//
// Created by Chunbin lin on 5/31/20.
//

class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (i >= 0 && j >= 0) {
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int added = a + b + c;
            result.push_back(added % 10 + '0');
            c = added / 10;
            i--;
            j--;
        }

        if (j >= 0)
        {
            while (j >= 0) {
                int val = (num2[j] - '0') + c;
                result.push_back(val % 10 + '0');
                c = val / 10;
                j--;
            }
        } else if (i >= 0) {
            while (i >= 0) {
                int val = (num1[i] - '0') + c;
                result.push_back(val % 10 + '0');
                c = val / 10;
                i--;
            }
        }
        if (c) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }


};