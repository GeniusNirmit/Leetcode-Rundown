class Solution
{
    int countSubsets(vector<int> &a, int maxOrVal, int currentOrVal, int ind, vector<vector<int>> &dp)
    {
        int n = a.size();

        if (ind == n)
        {
            if (currentOrVal == maxOrVal)
                return 1;
            return 0;
        }

        if (dp[ind][currentOrVal] != -1)
            return dp[ind][currentOrVal];

        int pick = countSubsets(a, maxOrVal, currentOrVal, ind + 1, dp);
        int notPick = countSubsets(a, maxOrVal, currentOrVal | a[ind], ind + 1, dp);

        return dp[ind][currentOrVal] = pick + notPick;
    }

public:
    int countMaxOrSubsets(vector<int> &a)
    {
        int n = a.size();
        int maxOrVal = 0;

        for (int i = 0; i < n; i++)
            maxOrVal |= a[i];

        vector<vector<int>> dp(n + 1, vector<int>(maxOrVal + 1, -1));
        return countSubsets(a, maxOrVal, 0, 0, dp);
    }
};