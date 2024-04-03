class Solution
{
    bool minSplit(vector<int> &a, int k, int minMaxSum)
    {
        int n = a.size();
        int sum = 0, currentK = 1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > minMaxSum)
                return false;

            if (sum + a[i] > minMaxSum)
            {
                currentK++;
                sum = a[i];
            }
            else
                sum += a[i];
        }

        if (currentK <= k)
            return true;
        return false;
    }

public:
    int splitArray(vector<int> &a, int k)
    {
        int n = a.size();
        int l = 0, h = 0, mid;

        for (int i = 0; i < n; i++)
        {
            l = max(l, a[i]);
            h += a[i];
        }

        if (k == n)
            return l;
        if (k == 1)
            return h;

        while (l < h)
        {
            mid = l + ((h - l) / 2);
            if (minSplit(a, k, mid))
                h = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};