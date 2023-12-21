class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int n = prices.size();

        int cheapest1 = INT_MAX, cheapest2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < cheapest1)
            {
                cheapest2 = cheapest1;
                cheapest1 = prices[i];
            }
            else if (prices[i] < cheapest2)
                cheapest2 = prices[i];
        }

        if (cheapest1 + cheapest2 > money)
            return money;
        return money - (cheapest1 + cheapest2);
    }
};