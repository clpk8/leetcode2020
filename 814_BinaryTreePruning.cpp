//
// Created by Chunbin lin on 7/12/20.
//

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : NULL;
    }
    bool containsOne(TreeNode* node) {
        if (!node) return false;
        bool left = containsOne(node->left);
        bool right = containsOne(node->right);
        //prune
        if (!left) node->left = NULL;
        if (!right) node->right = NULL;
        return node->val == 1 || left || right;
    }
};