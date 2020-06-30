//
// Created by Chunbin lin on 6/23/20.
//

class Solution {
public:
    int countNodes(TreeNode* root) {
        return root!= NULL ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
    }
};