class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int m = worker.length;
        int[][] projects = new int[n][2];
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            projects[i][0] = difficulty[i];
            projects[i][1] = profit[i];
        }

        Arrays.sort(projects, (a, b) -> a[1] - b[1]);
        Arrays.sort(worker);

        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (worker[i] >= projects[j][0]) {
                maxProfit += projects[j][1];
                i--;
            } else
                j--;
        }

        return maxProfit;
    }
}