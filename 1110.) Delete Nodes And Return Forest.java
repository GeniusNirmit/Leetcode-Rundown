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
    TreeNode traverse(TreeNode root, List<TreeNode> forest, Set<Integer> delSt) {
        if (root == null)
            return null;

        root.left = traverse(root.left, forest, delSt);
        root.right = traverse(root.right, forest, delSt);

        if (delSt.contains(root.val)) {
            if (root.left != null)
                forest.add(root.left);

            if (root.right != null)
                forest.add(root.right);

            return null;
        }

        return root;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> forest = new ArrayList<>();
        Set<Integer> delSt = new HashSet<>();

        for (int i = 0; i < to_delete.length; i++)
            delSt.add(to_delete[i]);

        root = traverse(root, forest, delSt);

        if (root != null)
            forest.add(root);

        return forest;
    }
}