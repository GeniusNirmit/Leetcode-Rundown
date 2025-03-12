class Solution {
    public int isPeakElement(int[][] mat, int row, int col) {
        int m = mat.length, n = mat[0].length;

        if ((col > 0 && mat[row][col] < mat[row][col - 1]))
            return -1;

        if ((col < n - 1 && mat[row][col] < mat[row][col + 1]))
            return 1;

        return 0;
    }

    public int[] findPeakGrid(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] peakElementInd = new int[2];

        int left = 0, right = n - 1;

        while (left <= right) {
            int center = left + (right - left) / 2;
            int maxRowInd = 0;

            for (int i = 0; i < m; i++) {
                if (mat[maxRowInd][center] < mat[i][center])
                    maxRowInd = i;
            }

            int flag = isPeakElement(mat, maxRowInd, center);
            if (flag == 0) {
                peakElementInd[0] = maxRowInd;
                peakElementInd[1] = center;
                return peakElementInd;
            } else if (flag == -1)
                right = center - 1;
            else
                left = center + 1;
        }

        return peakElementInd;
    }
}