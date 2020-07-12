//
// Created by Chunbin lin on 7/6/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode *findIntersection(ListNode *head) {
        ListNode *t = head, *h = head;

        while (h && h->next) {
            t = t->next;
            h = h->next->next;
            if (h == t) {
                return t;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;

        ListNode *interection = findIntersection(head);
        if (!interection) {
            return interection;
        }

        ListNode *t = interection, *h = head;
        while (t != h) {
            t = t->next;
            h = h->next;
        }
        return t;
    }
};