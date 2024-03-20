class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        int n = word.length();
        unordered_map<char, int> mp;
        multiset<int> st;
        int minDeletions = INT_MAX;

        for (int i = 0; i < n; i++)
            mp[word[i]]++;

        for (auto i : mp)
            st.insert(i.second);

        for (auto i : st)
        {
            int current = i;
            int currentDeletions = 0;

            for (auto j : st)
            {
                if (j - current > k)
                    currentDeletions += j - current - k;
                else if (j < current)
                    currentDeletions += j;
            }

            minDeletions = min(minDeletions, currentDeletions);
            if (minDeletions == 0)
                break;
        }

        if (minDeletions == INT_MAX)
            return 0;
        return minDeletions;
    }
};