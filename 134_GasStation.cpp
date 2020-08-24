//
// Created by Chunbin lin on 8/21/20.
//

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*

        gas  = [1,2,3,4,5]
        cost = [3,4,5,1,2]
        diff = [-2, -2, -2, 3, 3]
        */

        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};