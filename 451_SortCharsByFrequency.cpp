//
// Created by Chunbin lin on 5/22/20.
//

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }

        //now do a max heap
        //c++ default max heap
        priority_queue<pair<int, char>> pq;
        for (auto element : map) {
            pq.push(make_pair(element.second, element.first));
        }
        string result;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            char c = p.second;
            //now replicate char
            while (map[c] != 0) {
                result += c;
                map[c]--;
            }
        }
        return result;
    }
};