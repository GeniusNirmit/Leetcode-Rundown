class Solution
{
public:
    int maxProduct(vector<int> &a)
    {
        int n = a.size();
        int max1 = 0, max2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else
                max2 = max(max2, a[i]);
        }

        return (max1 - 1) * (max2 - 1);
    }
};