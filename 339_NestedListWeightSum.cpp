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

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int weight = 1;
        int sum = 0;
        dfs(sum, weight, nestedList);
        return sum;
    }
    void dfs(int& sum, int weight, vector<NestedInteger>& nestedList) {
        for (auto ne : nestedList) {
            if (ne.isInteger()) {
                sum += weight * ne.getInteger();
            } else {
                dfs(sum, weight + 1, ne.getList());
            }
        }
    }
};