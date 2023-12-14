class Solution
{
public:
    int minimumMountainRemovals(vector<int> &a)
    {
        int n = a.size();
        int maxLength = 0;
        vector<int> leftDp(n, 1), rightDp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && leftDp[i] < 1 + leftDp[j])
                    leftDp[i] = leftDp[j] + 1;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (a[i] > a[j] && rightDp[i] < 1 + rightDp[j])
                    rightDp[i] = rightDp[j] + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (leftDp[i] > 1 && rightDp[i] > 1)
                maxLength = max(maxLength, leftDp[i] + rightDp[i] - 1);
        }

        return n - maxLength;
    }
};