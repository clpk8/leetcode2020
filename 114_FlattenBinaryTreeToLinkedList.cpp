//
// Created by Chunbin lin on 8/29/20.
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

//do left first, then right.
//put left to the right, then insert right to the end
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = temp;

    }
};

//Stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }

            //If there is a left, put everything on the right to end of left->right.
//                     1
//                    / \
//                   2   5
//                  / \   \
//                 3   4   6

//                     1
//                      \
//                       2
//                      / \
//                     3   4
//                          \
//                           5
//                            \
//                             6
            // Then push curreng->right again to further process
            if (t->right) s.push(t->right);
        }


    }
};