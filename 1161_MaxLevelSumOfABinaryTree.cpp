//
// Created by Chunbin lin on 6/15/20.
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
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN;
        int result = 0;
        vector<vector<int>> nodes;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> adj;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                adj.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            nodes.push_back(adj);
        }

        //find max
        for (int i = 0; i < nodes.size(); i++) {
            int size = 0;
            for (auto node : nodes[i]) {
                size += node;
            }
            if (size > sum) {
                sum = size;
                result = i + 1;
            }
        }
        return result;

    }
};