class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.length();
        int maximumScore = 0, ones = 0, zeroes = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones++;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1')
                ones--;
            else
                zeroes++;

            maximumScore = max(maximumScore, ones + zeroes);
        }

        return maximumScore;
    }
};