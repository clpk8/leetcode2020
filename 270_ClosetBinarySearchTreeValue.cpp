//
// Created by Chunbin lin on 5/24/20.
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
    double distance;
    int result;
public:
    int closestValue(TreeNode* root, double target) {
        distance = LONG_MAX;
        result = 0;
        inorder(root, target);
        return result;
    }
    void inorder(TreeNode* root, double target) {
        if (root == NULL)
            return;
        if (abs(target - root->val) < distance) {
            result = root->val;
            distance = abs(target - root->val);
        }
        inorder(root->left, target);
        inorder(root->right, target);
    }
};
