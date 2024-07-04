/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode p = head;
        ListNode newHead = new ListNode(-1);
        ListNode q = newHead;

        while (p.next != null) {
            if (p.val == 0 && p.next != null) {
                int sum = 0;
                p = p.next;
                while (p.val != 0) {
                    sum += p.val;
                    p = p.next;
                }
                ListNode newNode = new ListNode(sum);
                q.next = newNode;
                q = q.next;
            }
        }

        return newHead.next;
    }
}