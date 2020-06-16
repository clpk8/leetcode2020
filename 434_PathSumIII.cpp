//
// Created by Chunbin lin on 6/13/20.
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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0]++;

        int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    void helper(TreeNode* p, int cur, int sum, int &total, unordered_map<int, int> &m) {
        if (!p) return;

        cur += p->val;
        int dif = cur - sum;
        if (m.find(dif) != m.end())
            total += m[dif];
        m[cur]++;

        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);

        m[cur]--;

    }
};