//first method, two pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int length = 0;
        ListNode* first = head;
        while (first) {
            length++;
            first = first->next;
        }
        length -= n;
        first = dummy;
        while (length > 0) {
            length --;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};



//one pass, fast and slow pointer modified
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1), *fast = dummy, *slow = dummy;
        dummy->next = head;
        //advande fast to n + 1
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }
        
        //move fast to end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;
    }
};

