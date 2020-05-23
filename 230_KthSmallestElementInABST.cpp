//
// Created by Chunbin lin on 5/20/20.
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums(2, 0);

        inorder(root, nums, k);
        return nums[1];
    }
private:
    void inorder(TreeNode* root, vector<int>& nums, int k) {
        if (!root) return;
        inorder(root->left, nums, k);
        //logic
        if (++nums[0] == k) {
            nums[1] = root->val;
            return;
        }
        inorder(root->right, nums, k);
    }
};