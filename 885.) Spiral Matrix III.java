class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        List<int[]> positions = new ArrayList<>();
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int steps = 1;
        int ind = 0;
        int x = rStart;
        int y = cStart;
        positions.add(new int[] { x, y });

        while (positions.size() < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    x += directions[ind][0];
                    y += directions[ind][1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols)
                        positions.add(new int[] { x, y });
                }
                ind = (ind + 1) % 4;
            }
            steps++;
        }

        return positions.toArray(new int[positions.size()][]);
    }
}