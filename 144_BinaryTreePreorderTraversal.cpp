//
// Created by Chunbin lin on 7/8/20.
//

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    void helper(TreeNode *root, vector<int>& list) {
        if (root) {
            list.push_back(root->val);
            if (root->left) {
                helper(root->left, list);
            }
            if (root->right) {
                helper(root->right, list);
            }
        }
    }
};

//iterative DFS

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (!root) return result;

        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return result;
    }
};