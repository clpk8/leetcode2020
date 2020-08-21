//
// Created by Chunbin lin on 6/8/20.
//

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> pos;
        vector<int> result;
        for (int i = 0; i < S.size(); i++) {
            pos[S[i]] = i;
        }

        int i = 0;
        while (i < S.size()) {
            int end = pos[S[i]];
            int j = i;
            while (j != end) {
                end = max(end, pos[S[j]]);
                //cout << end << " " << S[j] << endl;

                j++;

            }
            result.push_back(j - i + 1);
            i = j + 1;
        }

        return result;
    }
};

//same
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};
        vector<int> ans;
        vector<int> map(26, 0);
        for (int i = 0; i < S.size(); i++) {
            map[S[i] - 'a'] = i;
        }
        int left = 0, right = -1;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, map[S[i] -'a']);
            if (i == right) {
                //done
                ans.push_back(right - left + 1);
                right = -1;
                left = i + 1;
                continue;
            }

        }
        return ans;
    }
};