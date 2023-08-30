class Solution
{
public:
    long long minimumReplacement(vector<int> &a)
    {
        int n = a.size();
        long long counter = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
            {
                long long currCounter = (a[i] + a[i + 1] - 1) / a[i + 1];
                counter += currCounter - 1;
                a[i] /= currCounter;
            }
        }
        return counter;
    }
};