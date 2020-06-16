//
// Created by Chunbin lin on 6/15/20.
//

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && val != root->val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
