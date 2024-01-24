class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        vector<int> result;

        for (int i = 0; i < n - 1; i++)
        {
            matrix[i][i + 1] = 1;
            matrix[i + 1][i] = 1;
            matrix[i][i] = 0;
        }
        matrix[n - 1][n - 1] = 0;

        if (x != y)
        {
            matrix[x - 1][y - 1] = 1;
            matrix[y - 1][x - 1] = 1;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int counter = 0;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[j][k] == i)
                        counter++;
                }
            }
            result.push_back(counter);
        }
        return result;
    }
};