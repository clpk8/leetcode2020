//
// Created by Chunbin lin on 8/31/20.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            //completcated case
            if (root->left && root->right) {
                TreeNode *min = root->right;
                while (min->left) min = min->left; // find min
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            } else {
                TreeNode *new_root = root->left == nullptr ? root->right : root->left;
                root->left = root->right = nullptr;
                delete root;
                return new_root;
            }
        }
        return root;
    }

};