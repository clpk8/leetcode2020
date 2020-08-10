//
// Created by Chunbin lin on 7/13/20.
//

//DFS everylevel depth == size
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightView(root, result, 0);
        return result;
    }
private:
    void rightView(TreeNode* node, vector<int>& result, int currDepth) {
        if (!node) return;
        if (currDepth == result.size()) {
            result.push_back(node->val);
        }
        //since we doing right view, add first one in each level
        rightView(node->right, result, currDepth+1);
        rightView(node->left, result, currDepth+1);
    }
};

//BFS

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> adj;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                adj.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }
            //now we have ajd
            result.push_back(adj.back());
        }
        return result;
    }
};