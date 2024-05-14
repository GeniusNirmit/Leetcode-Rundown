class Solution
{
    int traverse(int m, int n, vector<vector<int>> &grid, int row, int col)
    {
        if (row == m || row < 0 || col == n || col < 0 || grid[row][col] == 0)
            return 0;

        int maxGold = 0;

        int currentVal = grid[row][col];
        grid[row][col] = 0;

        maxGold = max(maxGold, traverse(m, n, grid, row, col - 1));
        maxGold = max(maxGold, traverse(m, n, grid, row - 1, col));
        maxGold = max(maxGold, traverse(m, n, grid, row, col + 1));
        maxGold = max(maxGold, traverse(m, n, grid, row + 1, col));

        grid[row][col] = currentVal;

        return maxGold + currentVal;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                maxGold = max(maxGold, traverse(m, n, grid, i, j));
        }

        return maxGold;
    }
};