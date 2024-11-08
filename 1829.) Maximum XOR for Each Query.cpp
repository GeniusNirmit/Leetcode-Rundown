class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &a, int maximumBit)
    {
        int n = a.size();
        int maxBit = pow(2, maximumBit) - 1;
        int maxXor = 0;
        vector<int> queryResults;

        for (int i = 0; i < n; i++)
            maxXor ^= a[i];

        for (int i = 0; i < n; i++)
        {
            queryResults.push_back(maxXor ^ maxBit);
            maxXor ^= a[n - 1 - i];
        }

        return queryResults;
    }
};