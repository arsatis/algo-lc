/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution { 
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        int carryover = 0;
        while (l1 != null || l2 != null || carryover != 0) {
            if (l1 != null) {
                carryover += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                carryover += l2.val;
                l2 = l2.next;
            }
            curr.next = new ListNode(carryover % 10);
            carryover /= 10;
            curr = curr.next;
        }
        return dummy.next;
    }
}