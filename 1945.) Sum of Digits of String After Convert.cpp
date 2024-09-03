class Solution
{
public:
    long long transform(string numStr)
    {
        int n = numStr.length();
        long long num = 0;

        for (int i = 0; i < n; i++)
            num += numStr[i] - '0';

        return num;
    }

    int getLucky(string s, int k)
    {
        int n = s.length();

        string numStr = "";
        long long num = 0;

        for (int i = 0; i < n; i++)
            numStr += to_string(s[i] - 'a' + 1);

        while (k--)
        {
            num = transform(numStr);
            numStr = to_string(num);
        }

        return num;
    }
};