//
// Created by Chunbin lin on 7/10/20.
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
    int maxAncestorDiff(TreeNode* root, int min_val = 100000, int max_val = 0) {
        if (!root) return max_val - min_val;
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        return max(maxAncestorDiff(root->left, min_val, max_val), maxAncestorDiff(root->right, min_val, max_val));
    }
};