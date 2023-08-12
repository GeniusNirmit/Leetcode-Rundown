// Tabulation

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> current(amount + 1, 0);
            for (int j = 0; j <= amount; j++)
            {
                int notPick = prev[j];
                int pick = INT_MAX;
                if (j >= coins[i])
                    pick = 1 + current[j - coins[i]];
                current[j] = min(notPick, pick);
            }
            prev = current;
        }
        if (prev[amount] >= 1e9)
            return -1;
        return prev[amount];
    }
};

// Memoization

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int minDemoninations = combinations(n, coins, amount, n - 1, dp);
        if (minDemoninations >= 1e9)
            return -1;
        return minDemoninations;
    }
    int combinations(int n, vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[ind] == 0)
                return amount / coins[ind];
            else
                return 1e9;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int notPick = combinations(n, coins, amount, ind - 1, dp);
        int pick = INT_MAX;
        if (amount >= coins[ind])
            pick = 1 + combinations(n, coins, amount - coins[ind], ind, dp);
        return dp[ind][amount] = min(notPick, pick);
    }
};