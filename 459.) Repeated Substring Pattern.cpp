class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string newString = s;
        int n = s.length();

        for (int i = 0; i < n / 2; i++)
        {
            char temp = newString[n - 1];
            newString.pop_back();
            newString = temp + newString;
            if (newString == s)
                return true;
        }
        return false;
    }
};