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
    boolean traverse(TreeNode root, int target, StringBuilder path) {
        if (root == null)
            return false;
        if (root.val == target)
            return true;

        path.append("L");
        if (traverse(root.left, target, path))
            return true;
        path.setLength(path.length() - 1);

        path.append("R");
        if (traverse(root.right, target, path))
            return true;
        path.setLength(path.length() - 1);

        return false;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder sourcePath = new StringBuilder("");
        StringBuilder destPath = new StringBuilder("");
        StringBuilder path = new StringBuilder("");

        traverse(root, startValue, sourcePath);
        traverse(root, destValue, destPath);

        int i = 0;
        int m = sourcePath.length(), n = destPath.length();
        while (i < m && i < n && sourcePath.charAt(i) == destPath.charAt(i))
            i++;

        int ind = i;
        while (i < m) {
            path.append("U");
            i++;
        }

        i = ind;
        while (i < n) {
            path.append(destPath.charAt(i));
            i++;
        }

        return path.toString();
    }
}