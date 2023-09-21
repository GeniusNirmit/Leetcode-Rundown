class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        vector<int> prev(m + 1, 0);
        for (int i = 0; i <= m; i++)
            prev[i] = i;

        for (int i = 1; i <= n; i++)
        {
            vector<int> current(m + 1, 0);
            current[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    current[j] = prev[j - 1];
                else
                    current[j] = 1 + min(prev[j - 1], min(prev[j], current[j - 1]));
            }
            prev = current;
        }
        return prev[m];
    }
};