class Solution {
    boolean isMagicSquare(int[][] grid, int row, int col) {
        String sequence = "2943816729438167";
        String sequenceReversed = "7618349276183492";

        StringBuilder borderStr = new StringBuilder();
        int[] borderIndices = new int[] { 0, 1, 2, 5, 8, 7, 6, 3 };

        for (int i = 0; i < borderIndices.length; i++)
            borderStr.append(grid[row + borderIndices[i] / 3][col + (borderIndices[i] % 3)]);

        String border = borderStr.toString();

        if (grid[row][col] % 2 == 0 && (sequence.contains(border))
                || sequenceReversed.contains(border) && grid[row + 1][col + 1] == 5)
            return true;

        return false;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int counter = 0;
        int m = grid.length;
        int n = grid[0].length;

        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (isMagicSquare(grid, i, j))
                    counter++;
            }
        }
        return counter;
    }

}