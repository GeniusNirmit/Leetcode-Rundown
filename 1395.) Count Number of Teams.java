class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int[] dp = new int[n];
        int counter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (rating[i] > rating[j]) {
                    dp[i]++;
                    counter += dp[j];
                }
            }
        }

        dp = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (rating[i] < rating[j]) {
                    dp[i]++;
                    counter += dp[j];
                }
            }
        }

        return counter;
    }
}