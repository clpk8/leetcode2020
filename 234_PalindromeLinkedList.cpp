//
// Created by Chunbin lin on 5/21/20.
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
    bool isPalindrome(ListNode* head) {
        //now, slow and fast pointers
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //now check if odd or even LL
        if (fast) {
            //even
            slow = slow->next;
        }

        //reverse half
        slow = reverse(slow);

        //now compare
        while (slow) {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
private:
    //reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};