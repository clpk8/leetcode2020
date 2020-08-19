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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        maxDepth(root, result);
        return result;
    }
    int maxDepth(TreeNode* node, bool& result) {
        if (node == NULL) return 0;
        int l = maxDepth(node->left, result);
        int r = maxDepth(node->right, result);
        if (abs(l - r) > 1) result = false;
        return max(l, r) + 1;
    }
};