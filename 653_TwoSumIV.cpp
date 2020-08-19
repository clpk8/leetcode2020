//
// Created by Chunbin lin on 5/31/20.
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
private:
    unordered_set<int> set;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        if (set.count(k - root->val)) return true;
        set.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        //2 3 4 5 6 7
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == k) return true;
            else if (nums[i] + nums[j] < k) i++;
            else j--;
        }
        return false;
    }
    void inorder(TreeNode* node, vector<int>& nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }
};