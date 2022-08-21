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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        
        stack<ListNode*> s;
        while (head) {
            s.push(head);
            head = head->next;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (s.size() > 0) {
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy->next;
    }
};