/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    int counter = 0;

    List<Integer> traverse(TreeNode root, int distance) {

        if (root == null) {
            List<Integer> dist = new ArrayList<>();
            dist.add(0);
            return dist;
        }
        if (root.left == null && root.right == null) {
            List<Integer> dist = new ArrayList<>();
            dist.add(1);
            return dist;
        }

        List<Integer> dist = new ArrayList<>();
        List<Integer> leftDist = traverse(root.left, distance);
        List<Integer> rightDist = traverse(root.right, distance);

        int m = leftDist.size(), n = rightDist.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (leftDist.get(i) > 0 && rightDist.get(j) > 0 && leftDist.get(i) + rightDist.get(j) <= distance)
                    counter++;
            }
        }

        for (int i = 0; i < m; i++) {
            if (leftDist.get(i) > 0 && leftDist.get(i) < distance)
                dist.add(leftDist.get(i) + 1);
        }

        for (int i = 0; i < n; i++) {
            if (rightDist.get(i) > 0 && rightDist.get(i) < distance)
                dist.add(rightDist.get(i) + 1);
        }

        return dist;
    }

    public int countPairs(TreeNode root, int distance) {
        traverse(root, distance);
        return counter;
    }
}