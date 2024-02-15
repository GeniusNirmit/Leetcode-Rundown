class Solution
{
public:
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        int n = words.size();
        int counter = 0;
        int pairs = 0;
        vector<int> lengths;
        vector<int> mp(26);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].length(); j++)
                mp[words[i][j] - 'a']++;
            lengths.push_back(words[i].length());
        }

        for (int i = 0; i < 26; i++)
            pairs += mp[i] / 2;

        sort(lengths.begin(), lengths.end());

        for (int i = 0; i < n; i++)
        {
            if (pairs >= lengths[i] / 2)
            {
                pairs -= lengths[i] / 2;
                counter++;
            }
        }

        return counter;
    }
};