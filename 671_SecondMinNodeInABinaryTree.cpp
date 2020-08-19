//
// Created by Chunbin lin on 8/16/20.
//

class Solution {
private:
    long xs = LONG_MAX;
    long s = LONG_MAX;
public:
    int findSecondMinimumValue(TreeNode* root) {
        traversal(root);
        return s == LONG_MAX ? -1 : s;
    }
    void traversal(TreeNode* root) {
        if (!root) return;
        if (root->val < xs) {
            s = xs;
            xs = root->val;
        } else if (root->val > xs && root->val < s) {
            s = root->val;
        }
        traversal(root->left);
        traversal(root->right);
        return;
    }
};