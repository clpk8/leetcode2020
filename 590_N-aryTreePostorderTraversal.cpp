//
// Created by Chunbin lin on 7/8/20.
//


class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        if (!root) return result;

        s.push(root);
        while (!s.empty()) {
            Node *node = s.top();
            s.pop();
            result.push_back(node->val);
            for (auto child : node->children) {
                if (child)
                    s.push(child);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};