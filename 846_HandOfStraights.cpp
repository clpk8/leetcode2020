//
// Created by Chunbin lin on 6/6/20.
//

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> c; //map is sorted by key
        for (int i : hand) c[i]++;
        for (auto it: c) {
            cout << it.first << endl;
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; i--) {
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
                }
        }
        return true;
    }

};

//also
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> counts;
        for (int h : hand) ++counts[h];

        while (!counts.empty()) {
            auto it = counts.begin();
            int start = it->first;
            for (int j = 0; j < W; j++) {
                if (it == counts.end() || it->first != start + j) return false;
                auto prev = it++;
                if (--(prev->second) == 0) {
                    counts.erase(prev);
                }
            }
        }
        return true;
    }
};