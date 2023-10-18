class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current(2, 0);
            for (int j = 0; j <= 1; j++)
            {
                if (j)
                    current[j] = max(prev[0] - prices[i], prev[1]);
                else
                    current[j] = max(prev[1] + prices[i] - fee, prev[0]);
            }
            prev = current;
        }

        return prev[1];
    }
};