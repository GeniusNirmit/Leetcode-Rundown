class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int maxNum1 = Integer.MIN_VALUE, maxNum2 = Integer.MAX_VALUE;
        List<Integer> luckyNum = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int minNum = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++)
                minNum = Math.min(minNum, matrix[i][j]);
            maxNum1 = Math.max(maxNum1, minNum);
        }

        for (int i = 0; i < n; i++) {
            int minNum = Integer.MIN_VALUE;
            for (int j = 0; j < m; j++)
                minNum = Math.max(minNum, matrix[j][i]);
            maxNum2 = Math.min(maxNum2, minNum);
        }

        if (maxNum1 == maxNum2)
            luckyNum.add(maxNum1);
        return luckyNum;
    }
}