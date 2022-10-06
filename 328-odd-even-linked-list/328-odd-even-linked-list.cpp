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
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    ListNode* oddEvenList(ListNode* head) {
        int idx = 1;
        ListNode odd, even, *oddPtr = &odd, *evenPtr = &even;
        for (; head; ++idx, head = head->next) {
            if (idx & 1) oddPtr->next = head, oddPtr = oddPtr->next;
            else evenPtr->next = head, evenPtr = evenPtr->next;
        }
        oddPtr->next = even.next;
        evenPtr->next = nullptr;
        return odd.next;
    }
};