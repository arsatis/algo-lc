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
    ListNode* getMid(ListNode* head) {
        ListNode dummy(0, head), *prev = &dummy;
        while (head && head->next) {
            prev = prev->next;
            head = head->next->next;
        }
        ListNode* mid = prev->next;
        prev->next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0), *ptr = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list1 ? list1 : list2;
        return dummy.next;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        return merge(sortList(head), sortList(mid));
    }
};