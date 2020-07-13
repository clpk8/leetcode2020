//
// Created by Chunbin lin on 7/12/20.
//

class BSTIterator {
private:
    vector<int> nodes;
    int index;
    void inorder(TreeNode *root) {
        if (!root)return;
        this->inorder(root->left);
        nodes.push_back(root->val);
        this->inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->index = -1;
        this->inorder(root);
    }

    /** @return the next smallest number */
    int next() {
        return this->nodes[++this->index];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (this->index + 1) < this->nodes.size();
    }
};