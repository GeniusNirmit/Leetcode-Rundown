class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        int length = 0;
        boolean oddVal = false;
        Map<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++)
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) + 1);

        for (Map.Entry<Character, Integer> i : mp.entrySet()) {
            int val = i.getValue();

            if (val % 2 == 0)
                length += val;
            else {
                length += val - 1;
                oddVal = true;
            }
        }

        if (oddVal)
            ++length;

        return length;
    }
}