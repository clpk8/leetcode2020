//
// Created by Chunbin lin on 8/25/20.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto e : map) {
            ans.push_back(e.second);
        }
        return ans;
    }
};

//better encoding
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        string res(26, 'a');
        for (string str : strs) {
            string res(26, 'a');
            for (char c : str) {
                res[c - 'a']++;
            }
            map[res].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto e : map) {
            ans.push_back(e.second);
        }
        return ans;
    }
};