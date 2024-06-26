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
    TreeNode generateTree(int start, int end, List<Integer> elements) {
        if (start > end)
            return null;

        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(elements.get(mid));
        root.left = generateTree(start, mid - 1, elements);
        root.right = generateTree(mid + 1, end, elements);
        return root;
    }

    void inOrder(TreeNode root, List<Integer> elements) {
        if (root == null)
            return;

        inOrder(root.left, elements);
        elements.add(root.val);
        inOrder(root.right, elements);
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> elements = new ArrayList<>();
        inOrder(root, elements);
        return generateTree(0, elements.size() - 1, elements);
    }
}