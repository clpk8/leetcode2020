//
// Created by Chunbin lin on 8/10/20.
//

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for (auto ni : nestedList) {
            dfs(0, ni, result);
        }
        //process result
        int sum = 0;
        for (int i = result.size() - 1, level = 1; i >= 0; i--, level++) {
            sum += level * result[i];
        }
        return sum;

    }
    void dfs(int depth, NestedInteger &ni, vector<int>& nums) {
        if (nums.size() < depth + 1) nums.resize(depth + 1);
        if (ni.isInteger()) {
            nums[depth] += ni.getInteger();
        } else {
            for (auto n : ni.getList()) {
                dfs(depth + 1, n, nums);
            }
        }
    }
};