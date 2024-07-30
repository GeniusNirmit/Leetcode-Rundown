class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int aCounter = 0, bCounter = 0;
        int minDeletions = n;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a')
                aCounter++;
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a')
                aCounter--;
            minDeletions = Math.min(minDeletions, aCounter + bCounter);
            if (s.charAt(i) == 'b')
                bCounter++;
        }

        return minDeletions;
    }
}