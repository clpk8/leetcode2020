//
// Created by Chunbin lin on 6/22/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *prev = sentinel, *curr = head, *toDelete = NULL;
        while (curr != NULL) {
            if (curr->val == val) {
                //set toDlete and set prev to delete curr
                prev->next = curr->next;
                toDelete = curr;

            } else {
                //not equal, do not delete
                prev = curr;
            }

            //curr always move
            curr = curr->next;

            //free the node
            if (toDelete) {
                delete toDelete;
                toDelete = NULL;
            }
        }
        //free sentinel node
        ListNode* ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};