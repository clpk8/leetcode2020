//
// Created by Chunbin lin on 5/31/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        vector<int> maxCount(1);
        rec(root, 0, 0, maxCount);
        return maxCount[0];
    }

private:
    void rec(TreeNode* root, int count, int target, vector<int>& maxCount) {
        if (!root) {
            return;
        } else if (root->val == target) {
            count++;
        } else {
            count = 1;
        }

        maxCount[0] = max(maxCount[0], count);
        rec(root->left, count, root->val+1, maxCount);
        rec(root->right, count, root->val+1, maxCount);
    }
};