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
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode *p = l1->next, *q = l2->next, *r = head;
        int C = (l1->val + l2->val) / 10;
        
        while (p || q || C) {
            int val = (p ? p->val : 0) + (q ? q->val : 0) + C;
            C = val / 10;
            r->next = new ListNode(val % 10);
            r = r->next;
            p = p ? p->next : p;
            q = q ? q->next : q;
        }
        
        return head;
    }
};