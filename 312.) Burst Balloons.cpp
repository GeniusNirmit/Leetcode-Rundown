class Solution
{
public:
    int maxCoins(vector<int> &a)
    {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                int maxCoins = 0;
                if (i <= j)
                {
                    for (int k = i; k <= j; k++)
                    {
                        int coins = a[i - 1] * a[k] * a[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                        maxCoins = max(maxCoins, coins);
                    }
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n];
    }
};