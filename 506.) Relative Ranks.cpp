class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> ranks(n);

        int maxVal = 0;
        for (int i = 0; i < n; i++)
            maxVal = max(maxVal, score[i]);
        vector<int> mp(maxVal + 1, 0);

        for (int i = 0; i < n; i++)
            mp[score[i]] = i + 1;

        int ind = 1;
        for (int i = maxVal; i >= 0; i--)
        {
            if (mp[i] != 0)
            {
                if (ind == 1)
                    ranks[mp[i] - 1] = "Gold Medal";
                else if (ind == 2)
                    ranks[mp[i] - 1] = "Silver Medal";
                else if (ind == 3)
                    ranks[mp[i] - 1] = "Bronze Medal";
                else if (ind >= 4)
                    ranks[mp[i] - 1] = to_string(ind);
                ind++;
            }
        }

        return ranks;
    }
};