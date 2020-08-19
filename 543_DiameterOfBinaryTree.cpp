//
// Created by Chunbin lin on 8/16/20.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        maxLen(root, result);
        return result;
    }
    int maxLen(TreeNode* root, int& result) {
        if (!root) return 0;
        int l = maxLen(root->left, result);
        int r = maxLen(root->right, result);
        result = max(result, r + l);
        return max(l, r) + 1;
    }
};