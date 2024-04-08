class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        if (k == 0)
            return s;

        int n = s.length();
        string smallestString = s;

        for (int i = 0; i < n; i++)
        {
            int currentDistance = min(s[i] - 'a', 26 - (s[i] - 'a'));
            if (currentDistance <= k)
            {
                smallestString[i] = 'a';
                k -= currentDistance;
            }
            else if (k > 0)
            {
                if (s[i] - k >= 'a')
                    smallestString[i] = s[i] - k;
                else
                    smallestString[i] = 'z' - k + 1;
                k = 0;
            }
        }

        return smallestString;
    }
};