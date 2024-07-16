class Solution {

    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> mp = new HashMap<>();
        Set<Integer> st = new HashSet<>();

        for (int[] description : descriptions) {
            int parentValue = description[0];
            int childValue = description[1];
            boolean isLeft = description[2] == 1;

            if (!mp.containsKey(parentValue))
                mp.put(parentValue, new TreeNode(parentValue));
            if (!mp.containsKey(childValue))
                mp.put(childValue, new TreeNode(childValue));

            if (isLeft)
                mp.get(parentValue).left = mp.get(childValue);
            else
                mp.get(parentValue).right = mp.get(childValue);
            st.add(childValue);
        }

        for (TreeNode node : mp.values()) {
            if (!st.contains(node.val))
                return node;
        }

        return null;
    }
}