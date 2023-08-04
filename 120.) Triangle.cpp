class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> next(n, 0), current(n, 0);
        for (int i = 0; i < n; i++)
            next[i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
                current[j] = triangle[i][j] + min(next[j], next[j + 1]);
            next = current;
        }
        return next[0];
    }
};