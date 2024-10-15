class Solution
{
public:
    long long minimumSteps(string s)
    {
        int n = s.length();
        long long counter = 0;
        int whiteBallInd = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                counter += (i - whiteBallInd - 1);
                whiteBallInd++;
            }
        }
        return counter;
    }
};