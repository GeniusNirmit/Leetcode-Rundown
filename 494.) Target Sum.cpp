class Solution
{
public:
    int findTargetSumWays(vector<int> &a, int k)
    {
        int sum = 0;
        int n = a.size();
        for (int i = 0; i < n; i++)
            sum += a[i];

        if (sum - k < 0 || (sum - k) & 1)
            return 0;

        int target = (sum - k) / 2;

        vector<int> prev(target + 1, 0);

        if (a[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        if (a[0] != 0 && a[0] <= target)
            prev[a[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = target; j >= 0; j--)
            {
                int current = 0;
                if (a[i] <= j)
                    current = prev[j - a[i]];
                prev[j] += current;
            }
        }
        return prev[target];
    }
};