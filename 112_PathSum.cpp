//
// Created by Chunbin lin on 6/13/20.
//

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;

        sum -= root->val;
        //check if end
        if (root->left == NULL && root->right == NULL) {
            return sum == 0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->left == NULL && root->right == NULL && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};