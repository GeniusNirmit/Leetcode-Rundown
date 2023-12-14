class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int counter = 0;
        vector<int> col(m, 0);
        vector<int> row(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    counter++;
            }
        }
        return counter;
    }
};