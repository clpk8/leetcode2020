//
// Created by Chunbin lin on 8/16/20.
//

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int paths = 0;
        dfs(root, paths);
        return paths;
    }
    int dfs(TreeNode* root, int& paths) {
        if (!root) return 0;
        int l = dfs(root->left, paths);
        int r = dfs(root->right, paths);
        int leftPaths = root->left != NULL && root->left->val == root->val ? l + 1 : 0;
        int rightPaths = root->right != NULL && root->right->val == root->val ? r + 1: 0;
        paths = max(paths,(leftPaths + rightPaths));
        return max(leftPaths, rightPaths);
    }
};