//
// Created by Chunbin lin on 8/16/20.
//

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        //Only trick is that the tree might have a null on onesite, which is not min depth
        if (r == 0 || l == 0) return max(l, r) + 1;
        else return min(l, r) + 1;
    }
};