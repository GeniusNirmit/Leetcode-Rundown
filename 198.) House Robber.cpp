class Solution
{
public:
    int rob(vector<int> &a)
    {
        int n = a.size();
        int prev = a[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int picked = a[i];
            if (i > 1)
                picked += prev2;

            int notPicked = prev;

            int current = max(picked, notPicked);
            prev2 = prev;
            prev = current;
        }

        return prev;
    }
};