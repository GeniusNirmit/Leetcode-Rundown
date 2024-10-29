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

class BSTIterator {
    private Stack<TreeNode> st = new Stack<>();
    private boolean reverse;

    public BSTIterator(TreeNode root, boolean reverse) {
        this.reverse = reverse;
        pushAll(root);
    }

    private void pushAll(TreeNode root) {
        while (root != null) {
            st.push(root);

            if (reverse)
                root = root.right;
            else
                root = root.left;
        }
    }

    public int next() {
        TreeNode nextNode = st.pop();
        if (reverse)
            pushAll(nextNode.left);
        else
            pushAll(nextNode.right);

        return nextNode.val;
    }

    public boolean hasNext() {
        return !st.isEmpty();
    }
}

class Solution {
    public boolean findTarget(TreeNode root, int k) {
        BSTIterator leftIterator = new BSTIterator(root, false);
        BSTIterator rightIterator = new BSTIterator(root, true);

        int leftVal = leftIterator.next();
        int rightVal = rightIterator.next();

        while (leftVal < rightVal) {
            if (leftVal + rightVal == k)
                return true;
            else if (leftVal + rightVal < k)
                leftVal = leftIterator.next();
            else
                rightVal = rightIterator.next();
        }
        return false;
    }
}
