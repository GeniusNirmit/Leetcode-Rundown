class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &a)
    {
        int n = a.size(), counter = 0;
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)a[i] - (long long)a[j];
                int slices = 0;

                if (dp[j].count(diff))
                    slices = dp[j][diff];
                dp[i][diff] += slices + 1;
                counter += slices;
            }
        }
        return counter;
    }
};