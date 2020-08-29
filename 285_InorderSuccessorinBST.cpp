//
// Created by Chunbin lin on 7/6/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *candidate = NULL, *cur = root;

        while (cur) {
            if (cur->val > p->val) {
                candidate = cur;
                cur = cur->left;
            } else {
                // cur->val <= p->val
                cur = cur->right;
            }
        }
        return candidate;
    }
};


//inorder traversal with stack
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (b) return t;
            if (t == p) b = true;
            t = t->right;
        }
        return NULL;
    }
};