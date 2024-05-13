class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int sum = 0;

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                    grid[i][j] = !grid[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            int zeroCounter = 0, oneCounter = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[j][i] == 1)
                    oneCounter++;
                else
                    zeroCounter++;
            }

            if (zeroCounter > oneCounter)
            {
                for (int j = 0; j < m; j++)
                    grid[j][i] = !grid[j][i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            int currentSum = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    currentSum += pow(2, n - 1 - j);
            }
            sum += currentSum;
        }

        return sum;
    }
};