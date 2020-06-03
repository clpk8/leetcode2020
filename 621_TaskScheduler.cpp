//
// Created by Chunbin lin on 5/31/20.
//

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for (char c : tasks) {
            map[c]++;
        }

        priority_queue<int> maxHeap;

        for (auto it : map) {
            maxHeap.push(it.second);
        }

        int cycle = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            //now update cout needed
            for (int i = 0; i < temp.size(); i++) {
                if (--temp[i] > 0) {
                    maxHeap.push(temp[i]);
                }
            }

            //add cycle
            cycle += maxHeap.empty() ? temp.size() : n + 1;
        }
        return cycle;
    }
};