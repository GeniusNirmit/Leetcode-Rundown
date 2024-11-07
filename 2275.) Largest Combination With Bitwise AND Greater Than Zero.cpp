class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int n = candidates.size();
        vector<int> bits(24, 0);
        int maxCounter = 0;

        for (int i = 0; i < n; i++)
        {
            for (int ind = 0; ind < 24; ind++)
            {
                if (candidates[i] & 1)
                    bits[ind]++;
                candidates[i] = candidates[i] >> 1;
            }
        }

        for (int i = 0; i < 24; i++)
            maxCounter = max(maxCounter, bits[i]);

        return maxCounter;
    }
};