class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>> current(2, vector<int>(k + 1, 0));
            for (int j = 0; j <= 1; j++)
            {
                for (int l = 1; l <= k; l++)
                {
                    if (j)
                        current[j][l] = max(prev[0][l] - prices[i], prev[1][l]);
                    else
                        current[j][l] = max(prev[1][l - 1] + prices[i], prev[0][l]);
                }
            }
            prev = current;
        }

        return prev[1][k];
    }
};
