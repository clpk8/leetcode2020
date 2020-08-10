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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if (!root) return output;

        map<int, vector<int>> map; //0 is center, -1 is one left
        queue<pair<int, TreeNode*>> q; //location and node
        q.emplace(0, root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i< size; i++) {
                auto p = q.front().second; // node
                int loc = q.front().first;
                q.pop();
                map[loc].push_back(p->val); //for this loc, push back
                if (p->left) {
                    q.emplace(loc - 1, p->left);
                }
                if (p->right) {
                    q.emplace(loc + 1, p->right);
                }
            }
        }
        for (auto v : map) {
            output.push_back(v.second);
        }
        return output;
    }
};