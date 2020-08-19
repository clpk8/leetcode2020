//
// Created by Chunbin lin on 8/16/20.
//

//TLE

class Solution {
public:
    int rob(TreeNode* root) {
        // Two case, rob current, or rob next
        if (!root) return 0;
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};