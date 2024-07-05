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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if (head.next.next == null)
            return new int[] { -1, -1 };

        int ind = 0;
        List<Integer> criticalInd = new ArrayList<>();
        ListNode prev = head;
        ListNode current = head.next;

        while (current.next != null) {
            if (prev.val > current.val && current.val < current.next.val)
                criticalInd.add(ind);
            if (prev.val < current.val && current.val > current.next.val)
                criticalInd.add(ind);
            prev = current;
            current = current.next;
            ind++;
        }

        if (criticalInd.size() < 2)
            return new int[] { -1, -1 };

        int[] minMaxDistances = new int[2];
        int minDistance = criticalInd.get(criticalInd.size() - 1) - criticalInd.get(0);
        int maxDistance = criticalInd.get(criticalInd.size() - 1) - criticalInd.get(0);
        for (int i = 1; i < criticalInd.size(); i++)
            minDistance = Math.min(minDistance, criticalInd.get(i) - criticalInd.get(i - 1));

        minMaxDistances[0] = minDistance;
        minMaxDistances[1] = maxDistance;
        return minMaxDistances;
    }
}