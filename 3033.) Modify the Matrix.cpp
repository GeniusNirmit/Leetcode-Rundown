class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> maxCols(n);
        vector<vector<int>> answer = matrix;

        for (int i = 0; i < n; i++)
        {
            int maxVal = 0;
            for (int j = 0; j < m; j++)
                maxVal = max(maxVal, matrix[j][i]);
            maxCols[i] = maxVal;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (answer[i][j] == -1)
                    answer[i][j] = maxCols[j];
            }
        }
        return answer;
    }
};
