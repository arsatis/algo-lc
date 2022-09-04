/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        
        unordered_set<ListNode*> visited;
        while (head) {
            if (visited.find(head) != visited.end()) return head;
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};