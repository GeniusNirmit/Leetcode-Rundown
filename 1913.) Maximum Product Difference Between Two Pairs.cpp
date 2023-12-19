class Solution
{
public:
    int maxProductDifference(vector<int> &a)
    {
        int n = a.size();
        int small1 = INT_MAX, small2 = INT_MAX;
        int large1 = 0, large2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > large1)
            {
                large2 = large1;
                large1 = a[i];
            }
            else if (a[i] > large2)
                large2 = a[i];

            if (a[i] < small1)
            {
                small2 = small1;
                small1 = a[i];
            }
            else if (a[i] < small2)
                small2 = a[i];
        }

        return (large1 * large2) - (small1 * small2);
    }
};