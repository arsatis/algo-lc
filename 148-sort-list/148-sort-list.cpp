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
    ListNode* sortList(ListNode* head) {
        // O(n log n) time, O(n) space
        vector<int> list;
        while (head) {
            list.emplace_back(head->val);
            head = head->next;
        }
        sort(list.begin(), list.end());
        
        ListNode* dummy = new ListNode(), *curr = dummy;
        for (int i : list) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return dummy->next;
    }
};