//
// Created by Chunbin lin on 8/18/20.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head, *q = l1, *p = l2;
        int c = 0;
        while (q || p) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = c + x + y;
            c = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            if (q) q = q->next;
            if (p) p = p->next;
        }
        if (c) {
            ptr->next = new ListNode(c);
        }
        return head->next;
    }
};