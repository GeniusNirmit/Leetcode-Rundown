class Solution
{
public:
    int minimumSum(vector<int> &a)
    {
        int n = a.size();
        int minSum = INT_MAX;
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int minVal = a[0];
        for (int i = 0; i < n; i++)
        {
            minVal = min(minVal, a[i]);
            left[i] = minVal;
        }

        minVal = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            minVal = min(minVal, a[i]);
            right[i] = minVal;
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > left[i - 1] && a[i] > right[i + 1])
                minSum = min(minSum, a[i] + left[i - 1] + right[i + 1]);
        }

        if (minSum == INT_MAX)
            return -1;
        return minSum;
    }
};