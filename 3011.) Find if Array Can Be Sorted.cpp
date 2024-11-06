class Solution
{
public:
    bool canSortArray(vector<int> &a)
    {
        int n = a.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                if (__builtin_popcount(a[i]) == __builtin_popcount(a[i + 1]))
                    swap(a[i], a[i + 1]);
                else
                    return false;
            }
        }

        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i - 1])
            {
                if (__builtin_popcount(a[i]) == __builtin_popcount(a[i - 1]))
                    swap(a[i], a[i - 1]);
                else
                    return false;
            }
        }

        return true;
    }
};