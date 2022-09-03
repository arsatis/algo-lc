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
    ListNode* f(ListNode* prev, ListNode* curr) {
        if (!curr) return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        return f(curr, temp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        return f(nullptr, head);
    }
};