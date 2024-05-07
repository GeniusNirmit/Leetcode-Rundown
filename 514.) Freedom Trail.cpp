// Approach - 1 Recursive Memoization

class Solution
{
    int freedomTrail(string &ring, string &key, int ringPos, int pos, vector<vector<int>> &dp)
    {
        int n = key.size(), m = ring.size();

        if (pos == n)
            return 0;

        if (dp[ringPos][pos] != -1)
            return dp[ringPos][pos];

        int minSteps = 1e9;
        for (int i = 0; i < m; i++)
        {
            if (key[pos] == ring[i])
            {
                int currentSteps = min(abs(ringPos - i), abs(m - abs(ringPos - i))) + 1;
                minSteps = min(minSteps, currentSteps + freedomTrail(ring, key, i, pos + 1, dp));
            }
        }

        return dp[ringPos][pos] = minSteps;
    }

public:
    int findRotateSteps(string ring, string key)
    {
        int n = key.size(), m = ring.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return freedomTrail(ring, key, 0, 0, dp);
    }
};