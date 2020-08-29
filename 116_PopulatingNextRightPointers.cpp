/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        //connect 2 -> 3 in the example
        root->left->next = root->right;
        //connect 5 -> 6
        if (root->next) {
            // for example, 2 has next of 3
            root->right->next = root->next->left;
        }

        //connect left and right
        connect(root->left);
        connect(root->right);
        return root;
    }
};