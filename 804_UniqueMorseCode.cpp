//
// Created by Chunbin lin on 6/8/20.
//

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> set;
        for (auto word : words) {
            string morse;
            for (auto c : word) {
                morse += codes[c - 'a'];
            }
            set.insert(morse);
        }
        return set.size();
    }
};