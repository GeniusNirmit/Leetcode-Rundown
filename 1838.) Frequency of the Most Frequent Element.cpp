class Solution
{
public:
    int maxFrequency(vector<int> &a, int k)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        int maxFreq = 1;
        int i = 0, j = 1;
        long long sum = a[0];

        while (j < n)
        {
            sum += a[j];

            while (i < j && (long long)a[j] * (j - i + 1) - sum > k)
            {
                sum -= a[i];
                i++;
            }

            maxFreq = max(maxFreq, j - i + 1);
            j++;
        }
        return maxFreq;
    }
};