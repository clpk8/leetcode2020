//
// Created by Chunbin lin on 8/18/20.
//

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevNode = dummy;
        while (head && head->next) {

            // find the node to be swap
            ListNode* first = head;
            ListNode* second = head->next;

            //swap
            prevNode->next = second;
            first->next = second->next;
            second->next = first;

            //change head
            prevNode = first;
            head = head->next; // jump 2 nodes
        }
        return dummy->next;
    }
};