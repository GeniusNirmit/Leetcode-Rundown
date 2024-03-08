class Solution
{
public:
    int maxFrequencyElements(vector<int> &a)
    {
        int n = a.size();
        int counter = 0, maxFreq = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            int currentFreq = mp[a[i]];

            if (currentFreq > maxFreq)
            {
                maxFreq = currentFreq;
                counter = currentFreq;
            }
            else if (currentFreq == maxFreq)
                counter += currentFreq;
        }

        return counter;
    }
};