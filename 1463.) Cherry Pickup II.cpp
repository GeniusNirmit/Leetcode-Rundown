class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return traverse(grid, m, n, 0, 0, n - 1, dp);
    }
    int traverse(vector<vector<int>> &grid, int m, int n, int row, int col1, int col2, vector<vector<vector<int>>> &dp)
    {
        if (row >= m || col1 >= n || col2 >= n || col1 < 0 || col2 < 0)
            return -1;
        if (row == m - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        vector<int> delCol = {-1, 0, 1};
        int maxValue = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int current = 0;
                if (col1 == col2)
                    current = grid[row][col1];
                else
                    current = grid[row][col1] + grid[row][col2];
                current += traverse(grid, m, n, row + 1, col1 + delCol[i], col2 + delCol[j], dp);

                maxValue = max(maxValue, current);
            }
        }

        return dp[row][col1][col2] = maxValue;
    }
};