class Solution {
    int countIslands(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int counter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    counter++;
                    traverse(grid, i, j, visited);
                }
            }
        }
        return counter;
    }

    void traverse(int[][] grid, int row, int col, boolean[][] visited) {
        int m = grid.length, n = grid[0].length;
        visited[row][col] = true;

        int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1
                    && !visited[newRow][newCol])
                traverse(grid, newRow, newCol, visited);
        }
    }

    public int minDays(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        if (countIslands(grid) != 1)
            return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;

                    if (countIslands(grid) != 1)
                        return 1;

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
}