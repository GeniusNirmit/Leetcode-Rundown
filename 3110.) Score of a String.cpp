class Solution
{
public:
    int scoreOfString(string s)
    {
        int n = s.length();

        int score = 0;
        for (int i = 1; i < n; i++)
            score += abs(s[i] - s[i - 1]);

        return score;
    }
};