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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(0, head), *curr = dummy;
        
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }
        s.push(nullptr);
        
        for (int i = 1; i < n; ++i) s.pop();
        ListNode* temp = s.top();
        s.pop();
        s.pop();
        s.top()->next = temp;
        
        return dummy->next;
    }
};