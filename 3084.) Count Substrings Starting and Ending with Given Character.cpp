class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        int n = s.length();
        long long frequency = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
                frequency++;
        }

        return (frequency * (frequency + 1)) / 2;
    }
};