//
// Created by Chunbin lin on 8/27/20.
//

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // -1, -1, -1, 0, 1, 0, 0, 1, 2, 3, 4, 0
        //  3   2   1  0  1  0  0  4  3  2  1  0
        vector<int> dis(S.size());
        int lastSeen = -1;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                lastSeen = i;
                dis[i] = 0;
            } else  {
                if (lastSeen == -1) {
                    dis[i] = INT_MAX;
                } else {
                    dis[i] = i - lastSeen;
                }
            }
        }

        //now go from back to front
        lastSeen = -1;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                lastSeen = i;
                dis[i] = 0;
            } else {
                if (lastSeen == -1) {
                    dis[i] = min(INT_MAX, dis[i]);
                } else {
                    dis[i] = min(dis[i], lastSeen - i);
                }
            }
        }
        return dis;
    }
};