//
// Created by Chunbin lin on 8/24/20.
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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return generate_Tree(1, n);
    }
private:
    vector<TreeNode*> generate_Tree(int l, int r) {
        vector<TreeNode*> allTrees;
        //append leave NULLs
        if (l > r) {
            allTrees.push_back(NULL);
            return allTrees;
        }

        for (int i = l; i <= r; i++) {
            auto leftTrees = generate_Tree(l, i - 1);
            auto rightTrees = generate_Tree(i + 1, r);

            for (TreeNode* lt : leftTrees) {
                for (TreeNode* rt: rightTrees) {
                    auto curr = new TreeNode(i);
                    curr->left = lt;
                    curr->right = rt;
                    allTrees.push_back(curr);
                }
            }
        }
        return allTrees;
    }
};