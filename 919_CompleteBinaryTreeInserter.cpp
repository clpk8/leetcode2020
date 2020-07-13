//
// Created by Chunbin lin on 7/12/20.
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
class CBTInserter {
private:
    TreeNode *root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
    }

    int insert(int v) {
        //make it most left
        while (q.front()->right) {
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        TreeNode* parent = q.front(), *n = new TreeNode(v);
        if (parent->left == NULL) {
            parent->left = n;
        } else {
            parent->right = n;
        }
        return parent->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */