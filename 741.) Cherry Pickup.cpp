class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, traverse(grid, n, 0, 0, 0, dp));
    }
    int traverse(vector<vector<int>> &grid, int n, int row1, int col1, int col2, vector<vector<vector<int>>> &dp)
    {
        int row2 = row1 + col1 - col2;
        if (row1 == n || row2 == n || col1 == n || col2 == n || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return -1e8;
        if (row1 == n - 1 && col1 == n - 1)
            return grid[row1][col1];
        if (dp[row1][col1][col2] != -1)
            return dp[row1][col1][col2];

        if (col1 == col2)
            return dp[row1][col1][col2] = grid[row1][col1] + max({traverse(grid, n, row1 + 1, col1, col2, dp), traverse(grid, n, row1, col1 + 1, col2, dp), traverse(grid, n, row1 + 1, col1, col2 + 1, dp), traverse(grid, n, row1, col1 + 1, col2 + 1, dp)});
        return dp[row1][col1][col2] = grid[row1][col1] + grid[row2][col2] + max({traverse(grid, n, row1 + 1, col1, col2, dp), traverse(grid, n, row1, col1 + 1, col2, dp), traverse(grid, n, row1 + 1, col1, col2 + 1, dp), traverse(grid, n, row1, col1 + 1, col2 + 1, dp)});
    }
};