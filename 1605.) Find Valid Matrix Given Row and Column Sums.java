class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.length, n = colSum.length;
        int[] currentRowSum = new int[m];
        int[] currentColSum = new int[n];
        int[][] originalMatrix = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                originalMatrix[i][j] = Math.min(rowSum[i] - currentRowSum[i], colSum[j] - currentColSum[j]);

                currentRowSum[i] += originalMatrix[i][j];
                currentColSum[j] += originalMatrix[i][j];
            }
        }
        return originalMatrix;
    }
}