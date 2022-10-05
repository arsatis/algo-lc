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
        ListNode *fast = head, *slow = head, *dummy = nullptr;
        
        // get to middle of list
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = dummy;
            dummy = slow;
            slow = tmp;
        }
        if (fast) slow = slow->next;
        
        // check initial reversed and remainder of list
        while (slow && dummy) {
            if (slow->val != dummy->val) return false;
            slow = slow->next;
            dummy = dummy->next;
        }
        return true;
    }
};