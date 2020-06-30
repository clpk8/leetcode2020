//
// Created by Chunbin lin on 6/29/20.
//

//Key is to id strings that are in same shift sequeunce
//encode a shifting feature "s[1] - s[0], s[2] - s[1], ..., s[n - 1] - s[n - 2],"

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        for (string s : strings) {
            map[shift(s)].push_back(s);
        }
        vector<vector<string>> groups;
        for (auto m : map) {
            vector<string> group = m.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        return groups;
    }

private:
    string shift(string& s) {
        string t;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26; //take care of az
            t += 'a' + diff + ',';
        }
        return t;
    }
};