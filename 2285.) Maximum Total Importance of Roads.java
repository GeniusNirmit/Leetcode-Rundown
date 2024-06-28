class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long[] degree = new long[n];
        long maxImportance = 0;

        for (int i = 0; i < roads.length; i++) {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        Arrays.sort(degree);
        long val = 1;

        for (int i = 0; i < n; i++) {
            maxImportance += val * degree[i];
            val++;
        }

        return maxImportance;
    }
}