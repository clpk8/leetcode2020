//
// Created by Chunbin lin on 5/23/20.
//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};