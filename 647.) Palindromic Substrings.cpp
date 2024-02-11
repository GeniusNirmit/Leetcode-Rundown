class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int counter = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
                counter += substrings(s, i, j, dp);
        }

        return counter;
    }
    int substrings(string s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = substrings(s, i + 1, j - 1, dp);
        return dp[i][j] = 0;
    }
};