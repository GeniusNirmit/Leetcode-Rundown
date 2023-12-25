class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();
        int length = source.length();
        long long minCost = 0;

        vector<vector<long long>> matrix(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < 26; i++)
            matrix[i][i] = 0;

        for (int i = 0; i < n; i++)
            matrix[original[i] - 'a'][changed[i] - 'a'] = min(1LL * cost[i], matrix[original[i] - 'a'][changed[i] - 'a']);

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (source[i] != target[i])
            {
                if (matrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                    return -1;
                else
                    minCost += matrix[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return minCost;
    }
};