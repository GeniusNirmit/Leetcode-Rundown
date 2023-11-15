class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        int counter = 0;
        unordered_set<char> letters(s.begin(), s.end());

        for (auto i : letters)
        {
            int start = -1;
            int end = 0;

            for (int j = 0; j < n; j++)
            {
                if (s[j] == i)
                {
                    if (start == -1)
                        start = j;
                    end = j;
                }
            }

            unordered_set<char> between;
            for (int j = start + 1; j < end; j++)
                between.insert(s[j]);
            counter += between.size();
        }
        return counter;
    }
};