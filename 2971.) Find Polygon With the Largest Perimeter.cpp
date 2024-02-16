class Solution
{
public:
    long long largestPerimeter(vector<int> &a)
    {
        int n = a.size();
        sort(a.begin(), a.end());

        long long sum = 0;
        long long maxPerimeter = -1;
        for (int i = 0; i < n; i++)
        {
            if (sum > a[i])
                maxPerimeter = a[i] + sum;
            sum += a[i];
        }

        return maxPerimeter;
    }
};