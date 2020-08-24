//
// Created by Chunbin lin on 8/16/20.
//

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (isLeaf(root->left)) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    bool isLeaf(TreeNode* node) {
        if (!node) return false;
        return node->left == NULL && node->right == NULL;
    }
};

//same
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};