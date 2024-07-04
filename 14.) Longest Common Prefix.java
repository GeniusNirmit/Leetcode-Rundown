class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        String prefix = strs[0];

        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix.charAt(j) == strs[i].charAt(j))
                j++;
            prefix = prefix.substring(0, j);
        }
        return prefix;
    }
}