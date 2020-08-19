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
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int c = 0;
        ListNode* head = NULL;
        while (!s1.empty() || !s2.empty() || c) {
            int x = s1.empty() ? 0 : s1.top();
            if (!s1.empty())s1.pop();
            int y = s2.empty() ? 0 : s2.top();
            if (!s2.empty())s2.pop();
            int sum = x + y + c;

            ListNode* n = new ListNode(sum % 10);
            n->next = head;
            head = n;
            c = sum / 10;
        }
        return head;
    }
};