class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();
        StringBuilder st = new StringBuilder("");
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ')')
                counter--;

            if (counter != 0)
                st.append(s.charAt(i));

            if (s.charAt(i) == '(')
                counter++;
        }

        return st.toString();
    }
}