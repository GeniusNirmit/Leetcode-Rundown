class Solution
{
public:
    bool isMonotonic(vector<int> &a)
    {
        int n = a.size();
        bool asc = false, desc = false;

        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] < a[i])
                asc = true;
            if (a[i - 1] > a[i])
                desc = true;

            if (asc & desc)
                return false;
        }
        return true;
    }
};