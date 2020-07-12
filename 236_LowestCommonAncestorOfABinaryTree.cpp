//
// Created by Chunbin lin on 7/5/20.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        //if both returns a valid node, p, q are in different substrres,root will be their LCA
        if (l && r) return root;
        //if only one valid, p, q are in the same subtree, return valid node
        return l ? l : r;
    }
};