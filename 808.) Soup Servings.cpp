class Solution
{
public:
    double soupServings(int n)
    {
        if (n == 0)
            return 0.5;
        if (n >= 4800)
            return 1;

        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        servings(dp, n, n);

        return dp[n][n];
    }
    double servings(vector<vector<double>> &dp, int soupA, int soupB)
    {
        if (soupA <= 0 && soupB <= 0)
            return 0.5;
        if (soupB <= 0)
            return 0;
        if (soupA <= 0)
            return 1.0;
        if (dp[soupA][soupB] != -1)
            return dp[soupA][soupB];

        return dp[soupA][soupB] = 0.25 * (servings(dp, soupA - 100, soupB) + servings(dp, soupA - 75, soupB - 25) + servings(dp, soupA - 50, soupB - 50) + servings(dp, soupA - 25, soupB - 75));
    }
};