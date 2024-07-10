class Solution {
    public int minOperations(String[] logs) {
        int n = logs.length;
        Stack<String> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (logs[i].equals("../")) {
                if (!st.empty())
                    st.pop();
            } else if (logs[i].equals("./"))
                continue;
            else
                st.push(logs[i]);
        }

        return st.size();
    }
}