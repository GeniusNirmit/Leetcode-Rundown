class Solution {
    public int appendCharacters(String s, String t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        int maxCharFound = 0, charFound = 0;
        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                charFound++;
                j++;
            }

            maxCharFound = Math.max(maxCharFound, charFound);
            i++;
        }

        return m - maxCharFound;
    }
}