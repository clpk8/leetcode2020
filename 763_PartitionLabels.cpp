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