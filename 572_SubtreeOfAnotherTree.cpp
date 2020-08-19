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

//
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSubtreeWithRoot(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSubtreeWithRoot(TreeNode* s, TreeNode* t) {
        if (!t && !s) return true;
        if (!t || !s) return false;
        if (s->val != t->val) return false;
        return isSubtreeWithRoot(s->left, t->left) && isSubtreeWithRoot(s->right, t->right);
    }
};