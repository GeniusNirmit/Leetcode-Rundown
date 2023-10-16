class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>> current(2, vector<int>(3, 0));
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    if (j)
                        current[j][k] = max(prev[0][k] - prices[i], prev[1][k]);
                    else
                        current[j][k] = max(prev[1][k - 1] + prices[i], prev[0][k]);
                }
            }
            prev = current;
        }

        return prev[1][2];
    }
};
