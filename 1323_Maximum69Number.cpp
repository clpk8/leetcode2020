//
// Created by Chunbin lin on 5/31/20.
//

class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        for (char &c : num_str) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(num_str);
    }
};