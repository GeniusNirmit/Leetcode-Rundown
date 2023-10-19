class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n = s.length(), m = t.length();
        string S, T;
        int skipChar = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '#')
                skipChar++;
            else if (skipChar)
                skipChar--;
            else
                S += s[i];
        }

        skipChar = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            if (t[i] == '#')
                skipChar++;
            else if (skipChar)
                skipChar--;
            else
                T += t[i];
        }

        return S == T;
    }
};