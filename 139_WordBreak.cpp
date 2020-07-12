//
// Created by Chunbin lin on 7/5/20.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Construct hashset
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }
private:
    bool wordBreak(const string& s, const unordered_set<string>& dict) {
        //recursive call, stopping point
        if (mem.count(s)) return mem[s]; //already have result
        if (dict.count(s)) {
            mem[s] = true; //have the word
            return true;
        }

        //try break the word
        for (int i = 1; i < s.size(); i++) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);

            //find solition
            if (dict.count(right) && wordBreak(left, dict)) {
                mem[s] = true;
                return true;
            }
        }
        mem[s] = false;
        return false;
    }
    //memory
    unordered_map<string, bool> mem;
};