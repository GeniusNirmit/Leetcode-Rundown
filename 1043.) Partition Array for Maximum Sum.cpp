class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int maxSum = 0;
            int len = 0;
            int maxElement = -1;
            for (int j = i; j < min(n, i + k); j++)
            {
                len++;
                maxElement = max(maxElement, a[j]);
                int sum = len * maxElement + dp[j + 1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
};