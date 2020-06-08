//
// Created by Chunbin lin on 6/7/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> adj;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                adj.push_back(node->val);
                for (auto child : node->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
            result.push_back(adj);
        }
        return result;
    }
};