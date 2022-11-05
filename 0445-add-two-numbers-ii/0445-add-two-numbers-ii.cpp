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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode* dummy = new ListNode(), *sum = dummy;
        int c = 0;
        while (l1 || l2 || c != 0) {
            if (l1) c += l1->val, l1 = l1->next;
            if (l2) c += l2->val, l2 = l2->next;
            sum->next = new ListNode(c % 10);
            c /= 10;
            sum=sum->next;
        }
        dummy->next = reverse(dummy->next);
        return dummy->next;
    }
};
