//
// Created by Chunbin lin on 5/24/20.
//

//recursive
class Solution {
    int sum;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        inorder(root, L, R);
        return sum;
    }
    void inorder(TreeNode* root, int L, int R) {
        if (root == NULL)
            return;
        if (root->val >= L && root->val <= R)
            sum += root->val;
        inorder(root->left, L, R);
        inorder(root->right, L, R);

    }
};

//iterative


class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node != NULL) {
                if (L <= node->val && node->val <= R)
                    ans += node->val;
                if (L < node->val)
                    s.push(node->left);
                if (node->val < R)
                    s.push(node->right);
            }
        }
        return ans;
    }
};