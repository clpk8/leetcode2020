//
// Created by Chunbin lin on 7/8/20.
//

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        if (!root) return result;

        s.push(root);
        while (!s.empty()) {
            Node *node = s.top();
            s.pop();
            result.push_back(node->val);
            std::reverse(node->children.begin(), node->children.end());
            for (auto child : node->children) {
                s.push(child);
            }
        }
        return result;
    }
};