// Approach - 1 Recursive Memoization

class Solution
{
    int idealString(string s, int k, int ind, int prev, vector<vector<int>> &dp)
    {
        int n = s.length();

        if (ind == n)
            return 0;

        if (dp[ind][prev] != -1)
            return dp[ind][prev];

        int pick = 0, notPick = 0;
        if (prev == 0 || int(abs(s[ind] - prev)) <= k)
            pick = idealString(s, k, ind + 1, s[ind], dp) + 1;
        notPick = idealString(s, k, ind + 1, prev, dp);

        return dp[ind][prev] = max(pick, notPick);
    }

public:
    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(123, -1));
        return idealString(s, k, 0, 0, dp);
    }
};

// Approach - 2 Iterative Bottom-up

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(123, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = 0; prev < 123; prev++)
            {
                int pick = 0, notPick = 0;

                if (prev == 0 || abs(s[ind] - prev) <= k)
                    pick = dp[ind + 1][s[ind]] + 1;

                notPick = dp[ind + 1][prev];

                dp[ind][prev] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};