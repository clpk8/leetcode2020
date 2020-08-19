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
    int pathSum(TreeNode* root, int sum) {
        //every node could be root
        if (!root) return 0;
        int ret = pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        return ret;
    }

    int pathSumStartWithRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        int ret = 0;
        if (root->val == sum) ret++;
        ret += pathSumStartWithRoot(root->left, sum - root->val) + pathSumStartWithRoot(root->right, sum - root->val);
        return ret;
    }
};