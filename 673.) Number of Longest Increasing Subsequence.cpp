class Solution
{
public:
    int findNumberOfLIS(vector<int> &a)
    {
        int n = a.size();
        int maxCounter = 0, maxLength = 1;
        vector<int> dp(n, 1), counter(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && dp[i] < 1 + dp[j])
                {
                    dp[i] = dp[j] + 1;
                    counter[i] = counter[j];
                }
                else if (a[i] > a[j] && dp[i] == 1 + dp[j])
                    counter[i] += counter[j];
            }
            maxLength = max(maxLength, dp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLength)
                maxCounter += counter[i];
        }

        return maxCounter;
    }
};