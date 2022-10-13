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
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};