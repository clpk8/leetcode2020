//
// Created by Chunbin lin on 6/9/20.
//

//time: O(N1+N2)
//Memory: O(2 * N1 + N2)
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        inHash(root1, target, s);
        return helper(root2, s);
    }
private:
    void inHash(TreeNode* r, int target, unordered_set<int>& s) {
        if (!r) return;
        inHash(r->left, target, s);
        s.insert(target - r->val);
        inHash(r->right, target, s);
        return;
    }

    bool helper(TreeNode* r, unordered_set<int>& s) {
        if (!r) return false;
        return helper(r->left, s) || s.count(r->val) || helper(r->right, s);
    }
};


//O(N1 + N2)
//O(N1 + max(N1, N2))

class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> s;
        unordered_set<int> set;

        //traverse first tree and store compleements
        while (!s.empty() || root1 != NULL) {
            while (root1 != NULL) {
                s.push(root1);
                root1 = root1->left;
            }
            root1 = s.top(); s.pop();
            set.insert(target - root1->val);
            root1 = root1->right;
        }

        while (!s.empty() || root2 != NULL) {
            while (root2 != NULL) {
                s.push(root2);
                root2 = root2->left;
            }

            root2 = s.top(); s.pop();
            if (set.count(root2->val)) {
                return true;
            }
            root2 = root2->right;
        }
        return false;
    }
};
