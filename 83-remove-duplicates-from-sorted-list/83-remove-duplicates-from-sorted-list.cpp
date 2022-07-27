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
    ListNode* deleteDuplicates(ListNode* head) {
        // iterative
        ListNode* headPtr = head;
        ListNode* currNode = head;
        ListNode* tmp;
        
        while (currNode != NULL && currNode->next != NULL) {
            tmp = currNode;
            while (currNode != NULL && currNode->next != NULL && 
                   currNode->val == currNode->next->val) {
                currNode = currNode->next;
            }
            tmp->next = currNode->next;
            currNode = currNode->next;
        }
        
        return headPtr;
    }
};