class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int minChocolates = 0;
        vector<int> chocolates(n, 1);

        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                chocolates[i] = chocolates[i - 1] + 1;
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i] < ratings[i - 1])
                chocolates[i - 1] = max(chocolates[i - 1], chocolates[i] + 1);
        }

        for (int i = 0; i < n; i++)
            minChocolates += chocolates[i];

        return minChocolates;
    }
};