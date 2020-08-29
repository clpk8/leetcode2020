//
// Created by Chunbin lin on 6/30/20.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto list : lists) {
            while (list) {
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while (!pq.empty()) {
            head->next = new ListNode(pq.top());
            pq.pop();
            head = head->next;
        }
        return dummy->next;
    }
};

//this without making new list
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        auto comp = [](ListNode* a, ListNode*b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        for (ListNode* list: lists) {
            if (list) q.push(list);

        }

        while (!q.empty()) {
            cur->next = q.top(); q.pop();
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }
};