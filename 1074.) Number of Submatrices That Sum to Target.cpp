class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int counter = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_map<int, int> mp;
                int sum = 0;
                mp[sum]++;
                for (int k = 0; k < m; k++)
                {
                    if (i > 0)
                        sum += matrix[k][j] - matrix[k][i - 1];
                    else
                        sum += matrix[k][j];

                    if (mp.find(sum - target) != mp.end())
                        counter += mp[sum - target];

                    mp[sum]++;
                }
            }
        }
        return counter;
    }
};