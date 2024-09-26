class TreeNode {
    int start;
    int end;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int start, int end) {
        this.start = start;
        this.end = end;
        this.left = null;
        this.right = null;
    }

    TreeNode(int start, int end, TreeNode left, TreeNode right) {
        this.start = start;
        this.end = end;
        this.left = left;
        this.right = right;
    }
};

class MyCalendar {
    private TreeNode root;

    public MyCalendar() {

    }

    public boolean book(int start, int end) {
        if (root == null) {
            root = new TreeNode(start, end);
            return true;
        }

        return insert(start, end, root);
    }

    public boolean insert(int start, int end, TreeNode root) {
        if (end <= root.start) {
            if (root.left == null) {
                root.left = new TreeNode(start, end);
                return true;
            }

            return insert(start, end, root.left);
        }

        if (start >= root.end) {
            if (root.right == null) {
                root.right = new TreeNode(start, end);
                return true;
            }

            return insert(start, end, root.right);
        }

        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */