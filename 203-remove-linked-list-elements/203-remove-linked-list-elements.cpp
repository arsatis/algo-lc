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
    ListNode* removeElements(ListNode* head, int val) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        for (ListNode* curr = dummy; curr->next;) {
            if (curr->next->val == val) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return dummy->next;
    }
};