//
// Created by Chunbin lin on 6/23/20.
//

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *next;
        while (curr) {
            //store nexe
            next = curr->next;

            //now change nex
            curr->next = prev;

            //move prev and curr forward
            prev = curr;
            curr = next;
        }
        return prev;
    }
};