//
// Created by Chunbin lin on 5/20/20.
//

//build a list
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
class BSTIterator {
private:
    vector<int> sortedNums;
    int index;

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        sortedNums.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        index = -1;
        inorder(root);
    }

    /** @return the next smallest number */
    int next() {
        return sortedNums[++index];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index + 1 < sortedNums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */