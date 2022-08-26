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
        ListNode* temp = new ListNode(), *curr = temp;
        int carry = 0, sum = 0, n1 = 0, n2 = 0;
        
        while (l1 || l2 || carry != 0) {
            if (!l1) n1 = 0;
            else n1 = l1->val;
            
            if (!l2) n2 = 0;
            else n2 = l2->val;
            
            sum = carry + n2 + n1;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return temp->next;
    }
};