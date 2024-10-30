class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class TreeData {
    int sum;
    int maxLeft;
    int minRight;

    TreeData(int sum, int maxLeft, int minRight) {
        this.sum = sum;
        this.maxLeft = maxLeft;
        this.minRight = minRight;
    }
}

class Solution {
    int maxSum = 0;

    TreeData findMaxSumBST(TreeNode root) {
        if (root == null)
            return new TreeData(0, Integer.MIN_VALUE, Integer.MAX_VALUE);

        TreeData leftSubtreeData = findMaxSumBST(root.left);
        TreeData rightSubtreeData = findMaxSumBST(root.right);

        if (root.val > leftSubtreeData.maxLeft && root.val < rightSubtreeData.minRight) {
            int sum = leftSubtreeData.sum + rightSubtreeData.sum + root.val;
            maxSum = Math.max(maxSum, sum);
            int maxLeft = Math.max(root.val, rightSubtreeData.maxLeft);
            int minRight = Math.min(root.val, leftSubtreeData.minRight);
            return new TreeData(sum, maxLeft, minRight);
        }

        return new TreeData(Math.max(leftSubtreeData.sum, rightSubtreeData.sum), Integer.MAX_VALUE, Integer.MIN_VALUE);
    }

    public int maxSumBST(TreeNode root) {
        findMaxSumBST(root);
        return maxSum;
    }
}