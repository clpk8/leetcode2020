//
// Created by Chunbin lin on 8/9/20.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (!root) return averages;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long total = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                total += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            averages.push_back(((double)total/size));

        }
        return averages;
    }
};