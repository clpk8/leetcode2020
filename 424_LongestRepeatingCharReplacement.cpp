//
// Created by Chunbin lin on 5/18/20.
//

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> char_counts(26, 0);

        int window_start = 0, max_length = 0, max_count = 0;

        //loop window end
        for (int window_end = 0; window_end < n; window_end++) {
            //add the count of current char
            char_counts[s[window_end] - 'A']++;
            max_count = max(max_count, char_counts[s[window_end] - 'A']); //keep track of the max count

            //now, check if we need to modifie our window
            while (window_end - window_start - max_count + 1 > k) {
                char_counts[s[window_start] - 'A']--; //now we take out window_start
                window_start++;
            }
            //update our max
            max_length = max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
};