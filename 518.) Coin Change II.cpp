// Tabulation

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        vector<int> prev(amount + 1, 0);
        prev[0] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current(amount + 1);
            current[0] = 1;
            for (int j = 1; j <= amount; j++)
            {
                if (j - coins[i] < 0)
                    current[j] = prev[j];
                else
                    current[j] = current[j - coins[i]] + prev[j];
            }
            prev = current;
        }
        return prev[amount];
    }
};

// Memoization

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return combinations(n, coins, amount, 0, dp);
    }
    int combinations(int n, vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;
        if (ind == n)
            return 0;
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        if (amount - coins[ind] < 0)
            return dp[ind][amount] = combinations(n, coins, amount, ind + 1, dp);

        return dp[ind][amount] = combinations(n, coins, amount - coins[ind], ind, dp) + combinations(n, coins, amount, ind + 1, dp);
    }
};