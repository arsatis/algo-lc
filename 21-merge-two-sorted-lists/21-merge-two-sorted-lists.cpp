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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        ListNode* dummy = new ListNode();
        for (ListNode* curr = dummy; list1 || list2;) {
            if (!list1) {
                curr->next = list2;
                list2 = list2->next;
            } else if (!list2 || list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;                
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};