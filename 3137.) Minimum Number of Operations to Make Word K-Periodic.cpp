class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int n = word.length();
        unordered_map<string, int> mp;
        int counter = 0, maxVal = 0;

        for (int i = 0; i < n; i += k)
        {
            string current = "";
            for (int j = 0; j < k; j++)
                current += word[i + j];
            mp[current]++;
        }

        for (auto i : mp)
        {
            counter += i.second;
            maxVal = max(maxVal, i.second);
        }

        counter -= maxVal;
        return counter;
    }
};