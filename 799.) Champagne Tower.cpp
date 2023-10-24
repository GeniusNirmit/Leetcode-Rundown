class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> prev;
        prev.push_back({(double)poured});

        for (int i = 1; i <= query_row; i++)
        {
            vector<double> current(i + 1, 0);
            for (int j = 1; j <= i; j++)
            {
                double excess = prev[j - 1] - 1;

                if (excess > 0)
                {
                    current[j - 1] += excess / 2.0;
                    current[j] += excess / 2.0;
                }
            }
            prev = current;
        }

        if (prev[query_glass] >= 1)
            return 1;
        return prev[query_glass];
    }
};