class Solution
{
public:
    int firstMissingPositive(vector<int> &a)
    {
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            if (a[i] <= 0 || a[i] > n)
                a[i] = n + 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (abs(a[i]) <= n && a[abs(a[i]) - 1] > 0)
                a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};