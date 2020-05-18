//two pass
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //two loop, find satisfied and then find satisfied by x using sliding window
        int satisifed = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                //not grumpy
                satisifed += customers[i];
                //modifiy customer arr
                customers[i] = 0;
            }
        }
        
        //now use sliindg window to find best place to put x
        int bestEffort = 0, sum = 0;
        for (int i = 0, j = 0; j < customers.size(); j++) {
            //find best sum
            sum += customers[j];
            if (j - i == X) {
                //move window, take out customers[i]
                sum -= customers[i];
                i++; //move window
            }
            bestEffort = max(bestEffort, sum);
        }
        return satisifed + bestEffort;
    }
};