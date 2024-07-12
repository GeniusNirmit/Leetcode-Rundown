class Solution {
    public int maximumGain(String s, int x, int y) {
        int n = s.length();
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;

            s = new StringBuilder(s).reverse().toString();
        }

        int aCounter = 0, bCounter = 0, totalPoints = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a')
                aCounter++;
            else if (s.charAt(i) == 'b') {
                if (aCounter > 0) {
                    aCounter--;
                    totalPoints += x;
                } else
                    bCounter++;
            } else {
                totalPoints += Math.min(bCounter, aCounter) * y;
                aCounter = 0;
                bCounter = 0;
            }

        }

        totalPoints += Math.min(bCounter, aCounter) * y;
        return totalPoints;
    }
}