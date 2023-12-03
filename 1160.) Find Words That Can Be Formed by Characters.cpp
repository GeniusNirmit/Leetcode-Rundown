class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> mp(26, 0);
        int n = words.size(), m = chars.length();
        int counter = 0;

        for (int i = 0; i < m; i++)
            mp[chars[i] - 'a']++;

        for (int i = 0; i < n; i++)
        {
            bool good = true;
            vector<int> currentMp(26, 0);
            for (int j = 0; j < words[i].size(); j++)
                currentMp[words[i][j] - 'a']++;

            for (int j = 0; j < 26; j++)
            {
                if (mp[j] < currentMp[j])
                {
                    good = false;
                    break;
                }
            }
            if (good)
                counter += words[i].size();
        }
        return counter;
    }
};