//
// Created by Chunbin lin on 6/23/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        //put a pseduHead
        Node* pseudoHead = new Node(0, NULL, head, NULL);

        flattenDFS(pseudoHead, head);

        //detach suedo head
        //delete(pseudoHead->next->prev);
        pseudoHead->next->prev = NULL;
        return pseudoHead->next;
    }

    //attach curr to prev
    Node* flattenDFS(Node* prev, Node* curr) {
        if (curr == NULL) return prev;
        curr->prev = prev;
        prev->next = curr;

        //keep a temp for later
        Node* tempNext = curr->next;
        //get all the child to tail
        Node* tail = flattenDFS(curr, curr->child);
        //clear the child
        curr->child = NULL;

        //put temp on the tail of tail
        return flattenDFS(tail, tempNext);
    }
};