class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;
        int nextIdleTime = 0;
        long netWaitTime = 0;

        for (int i = 0; i < n; i++) {
            nextIdleTime = Math.max(customers[i][0], nextIdleTime) + customers[i][1];
            netWaitTime += nextIdleTime - customers[i][0];
        }

        double averageWaitTime = (double) netWaitTime / n;
        return averageWaitTime;
    }
}