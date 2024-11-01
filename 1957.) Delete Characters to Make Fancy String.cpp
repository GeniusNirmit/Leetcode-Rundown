class Solution
{
public:
    string makeFancyString(string s)
    {
        int n = s.length();
        string fancyStr = "";

        if (n < 3)
            return s;

        char prev = s[0];
        char current = s[1];
        fancyStr += prev;
        fancyStr += current;

        for (int i = 2; i < n; i++)
        {
            if (!(prev == current && current == s[i]))
                fancyStr += s[i];
            prev = current;
            current = s[i];
        }

        return fancyStr;
    }
};