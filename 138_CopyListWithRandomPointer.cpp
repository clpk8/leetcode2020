//
// Created by Chunbin lin on 5/28/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *res = new Node(head->val, NULL, NULL);
        Node *node = res;
        Node *curr = head->next;

        //node : clone
        unordered_map<Node*, Node*> hash;
        hash[head] = res;

        while (curr) {
            Node *t = new Node(curr->val, NULL, NULL);
            node->next = t;
            hash[curr] = t;
            node = node->next;
            curr = curr->next;
        }

        node = res;
        curr = head;

        while (curr) {
            node->random = hash[curr->random];
            node = node->next;
            curr = curr->next;
        }
        return res;
    }
};

//new
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map; // original: copy
        Node* ptr = head;

        Node* newHead = new Node(-1);
        Node* newHeadPtr = newHead;
        while (ptr) {
            newHeadPtr->next = new Node(ptr->val);
            newHeadPtr = newHeadPtr->next;
            map[ptr] = newHeadPtr;
            ptr = ptr->next;
        }
        ptr = head, newHeadPtr = newHead->next;
        while (ptr) {
            newHeadPtr->random = map[ptr->random];
            newHeadPtr = newHeadPtr->next;
            ptr = ptr->next;
        }

        return newHead->next;
    }
};