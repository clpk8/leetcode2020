//
// Created by Chunbin lin on 6/10/20.
//

//hash table, O(n * L)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s(folder.begin(), folder.end());
        vector<string> ans;
        for (const auto& file : folder) {
            string f = file;
            bool valid = true;
            while (!f.empty() && valid) {
                while (f.back() != '/') {
                    f.pop_back();
                }
                f.pop_back();
                if (s.count(f)) valid = false;
            }
            if (valid) ans.push_back(file);
        }
        return ans;
    }
};