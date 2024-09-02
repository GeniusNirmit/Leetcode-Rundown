class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    public Node connect(Node root) {
        if (root == null)
            return root;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node prev = q.poll();
            int n = q.size();

            if (prev != null && prev.left != null)
                q.add(prev.left);
            if (prev != null && prev.right != null)
                q.add(prev.right);

            for (int i = 0; i < n; i++) {
                Node current = q.poll();

                if (current != null && current.left != null)
                    q.add(current.left);
                if (current != null && current.right != null)
                    q.add(current.right);

                prev.next = current;
                prev = current;
            }
        }

        return root;
    }
}