class Solution
{
public:
    int minimumSum(vector<int> &a)
    {
        int n = a.size();
        int minSum = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] < a[j] && a[k] < a[j])
                        minSum = min(minSum, a[i] + a[j] + a[k]);
                }
            }
        }

        if (minSum == INT_MAX)
            return -1;
        return minSum;
    }
};