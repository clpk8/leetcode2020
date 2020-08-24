//
// Created by Chunbin lin on 8/22/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_set<Node*> done;
        unordered_map<Node*, Node*> map; //map node given to copy
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* t = q.front(); q.pop();
            if (done.count(t)) continue;
            done.insert(t);
            if (!map.count(t)) {
                map[t] = new Node(t->val);
            }
            //lets get the copy we created
            Node* copy = map[t];
            for (Node* tt : t->neighbors) {
                if (!map.count(tt))
                    map[tt] = new Node(tt->val);
                q.push(tt);
                copy->neighbors.push_back(map[tt]);
            }
        }
        return map[node];
    }
};