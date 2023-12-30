class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        int minDiff = jobDifficulties(n, jobDifficulty, 0, d, dp);

        if (minDiff == 1e9)
            return -1;
        return minDiff;
    }
    int jobDifficulties(int n, vector<int> &jobDifficulty, int ind, int d, vector<vector<int>> &dp)
    {
        if (ind >= n)
        {
            if (d == 0)
                return 0;
            return 1e9;
        }
        else if (d <= 0)
            return 1e9;
        if (dp[ind][d] != -1)
            return dp[ind][d];

        int currentDifficulty = 0, minDiff = 1e9;
        for (int i = ind; i < n; i++)
        {
            currentDifficulty = max(currentDifficulty, jobDifficulty[i]);
            minDiff = min(minDiff, currentDifficulty + jobDifficulties(n, jobDifficulty, i + 1, d - 1, dp));
        }

        return dp[ind][d] = minDiff;
    }
};