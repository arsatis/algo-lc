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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // find number of nodes in list
        int num = 1;
        ListNode *fast = head, *slow = head;
        while (fast->next) fast = fast->next, ++num;

        // get to position before new start
        k = num - (k % num);
        if (k == num) return head;
        for (int i = 1; i < k; ++i) slow = slow->next;

        // reconstruct list
        ListNode* tmp = slow->next;
        fast->next = head;
        slow->next = nullptr;
        return tmp;
    }
};
