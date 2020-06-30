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
    void reorderList(ListNode* head) {
        if (head == NULL) return;

        //find the middle of linked list, 876
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse second part of LL, 206
        ListNode *prev = NULL, *curr = slow, *temp;
        while (curr != NULL) {
            //store next before change
            temp = curr->next;
            //now change next, ithis is where reversing happen
            curr->next = prev;

            //move pre and curr one step forward
            prev = curr;
            curr=temp;
        }

        //merge two sorted LL, 21
        ListNode *first = head, *second = prev;
        while (second->next != NULL) {
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};