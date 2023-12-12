class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &a)
    {
        int n = a.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        vector<int> largestSubset;
        int maxLength = 1, lastInd = 0;

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            hash[i] = i;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] % a[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[i] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                lastInd = i;
            }
        }

        largestSubset.push_back(a[lastInd]);

        while (hash[lastInd] != lastInd)
        {
            lastInd = hash[lastInd];
            largestSubset.push_back(a[lastInd]);
        }

        reverse(largestSubset.begin(), largestSubset.end());
        return largestSubset;
    }
};