class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prevPrev(2, 0);
        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current(2, 0);
            for (int j = 0; j <= 1; j++)
            {
                if (j)
                    current[j] = max(prev[0] - prices[i], prev[1]);
                else
                    current[j] = max(prevPrev[1] + prices[i], prev[0]);
            }
            prevPrev = prev;
            prev = current;
        }

        return prev[1];
    }
};
