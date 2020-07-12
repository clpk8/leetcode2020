//
// Created by Chunbin lin on 7/9/20.
//

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
    int helper(vector<NestedInteger>& nestedList, int depth) {
        int total = 0;
        for (auto ne : nestedList) {
            if (ne.isInteger()) {
                total += depth * ne.getInteger();
            } else {
                total += helper(ne.getList(), depth+1);
            }
        }
        return total;
    }
};