/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder serializedStr = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();

        if (root == null)
            return "";

        q.add(root);

        while (!q.isEmpty()) {
            TreeNode current = q.poll();

            if (current == null)
                serializedStr.append('#').append(',');
            else {
                serializedStr.append(current.val).append(',');
                q.add(current.left);
                q.add(current.right);
            }
        }

        return serializedStr.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        int dataSize = data.length();

        if (data.isEmpty())
            return null;

        StringBuilder dataStream = new StringBuilder(data);
        Queue<TreeNode> q = new LinkedList<>();

        int commaInd = dataStream.indexOf(",");
        String num = dataStream.substring(0, commaInd);
        dataStream.delete(0, commaInd + 1);

        TreeNode root = new TreeNode(Integer.parseInt(num));
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode current = q.poll();

            commaInd = dataStream.indexOf(",");
            num = dataStream.substring(0, commaInd);
            dataStream.delete(0, commaInd + 1);

            if (!num.equals("#")) {
                current.left = new TreeNode(Integer.parseInt(num));
                q.add(current.left);
            }

            commaInd = dataStream.indexOf(",");
            num = dataStream.substring(0, commaInd);
            dataStream.delete(0, commaInd + 1);

            if (!num.equals("#")) {
                current.right = new TreeNode(Integer.parseInt(num));
                q.add(current.right);
            }
        }

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));