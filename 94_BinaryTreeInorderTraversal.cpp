//
// Created by Chunbin lin on 7/8/20.
//

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    void helper(TreeNode *root, vector<int>& list) {
        if (root) {
            if (root->left) {
                helper(root->left, list);
            }
            list.push_back(root->val);
            if (root->right) {
                helper(root->right, list);
            }
        }
    }
};

//ireative using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};