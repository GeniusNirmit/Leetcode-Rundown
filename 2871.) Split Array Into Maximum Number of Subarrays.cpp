class Solution
{
public:
    int maxSubarrays(vector<int> &a)
    {
        int val = a[0];
        int counter = 0;
        int n = a.size();
        for (int i = 1; i < n; i++)
            val &= a[i];

        if (val != 0)
            return 1;

        val = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            val &= a[i];
            if (val == 0)
            {
                counter++;
                val = INT_MAX;
            }
        }
        return counter;
    }
};