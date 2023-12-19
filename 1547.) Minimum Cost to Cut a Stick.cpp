class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int cutsSize = cuts.size();
        vector<vector<int>> dp(cutsSize + 2, vector<int>(cutsSize + 2, 0));

        cuts.push_back(n);
        cuts.push_back(0);

        sort(cuts.begin(), cuts.end());

        for (int i = cutsSize; i >= 1; i--)
        {
            for (int j = 1; j <= cutsSize; j++)
            {
                if (i <= j)
                {
                    int minCost = INT_MAX;
                    for (int k = i; k <= j; k++)
                    {
                        int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                        minCost = min(minCost, cost);
                    }
                    dp[i][j] = minCost;
                }
            }
        }

        return dp[1][cutsSize];
    }
};
