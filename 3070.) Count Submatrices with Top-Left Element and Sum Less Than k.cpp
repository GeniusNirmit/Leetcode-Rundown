class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int counter = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                grid[i][j] += grid[i][j - 1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                grid[i][j] += grid[i - 1][j];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] <= k)
                    counter++;
            }
        }
        return counter;
    }
};