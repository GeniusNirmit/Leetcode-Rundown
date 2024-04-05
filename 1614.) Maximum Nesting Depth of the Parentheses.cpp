class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.length();
        int maxVal = 0, counter = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                counter++;
            else if (s[i] == ')')
            {
                maxVal = max(maxVal, counter);
                counter--;
            }
        }

        return maxVal;
    }
};