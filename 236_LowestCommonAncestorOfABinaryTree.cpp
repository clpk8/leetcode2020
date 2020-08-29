//
// Created by Chunbin lin on 7/5/20.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        //if both returns a valid node, p, q are in different substrres,root will be their LCA
        if (l && r) return root;
        //if only one valid, p, q are in the same subtree, return valid node
        return l ? l : r;
    }
};

//itreative, what I did with Mike
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> findParent; // child, parent
        stack<TreeNode*> s;
        findParent[root] = NULL;
        s.push(root);
        while (!findParent.count(p) || !findParent.count(q)) {
            TreeNode* node = s.top(); s.pop();
            if (node->left) {
                findParent[node->left] = node;
                s.push(node->left);
            }
            if (node->right) {
                findParent[node->right] = node;
                s.push(node->right);
            }
        }

        //we have both
        unordered_set<TreeNode*> set;
        while (p) {
            set.insert(p);
            p = findParent[p];
        }

        while (!set.count(q)) {
            q = findParent[q];
        }
        return q;
    }
};