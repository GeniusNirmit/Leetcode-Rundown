class Solution
{
public:
    bool canSortArray(vector<int> &a)
    {
        int ind = 0, n = a.size();
        while (ind < n - 1)
        {
            int currSetBits = __builtin_popcount(a[ind]);
            int nextSetBits = __builtin_popcount(a[ind + 1]);
            if (a[ind] > a[ind + 1] && currSetBits == nextSetBits)
            {
                swap(a[ind], a[ind + 1]);
                ind = 0;
            }
            else if (a[ind] <= a[ind + 1])
                ind++;
            else if (a[ind] > a[ind + 1] && currSetBits != nextSetBits)
                return false;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
                return false;
        }
        return true;
    }
};