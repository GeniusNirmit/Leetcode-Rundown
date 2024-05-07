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

// Approach - 2 Iterative Bottom-up

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = key.size(), m = ring.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                int minSteps = 1e9;
                for (int k = 0; k < m; k++)
                {
                    if (key[i] == ring[k])
                    {
                        int currentSteps = min(abs(j - k), abs(m - abs(j - k))) + 1;
                        minSteps = min(minSteps, currentSteps + dp[k][i + 1]);
                    }
                }
                dp[j][i] = minSteps;
            }
        }

        return dp[0][0];
    }
};