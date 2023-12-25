class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.length();
        int counter = 0, minOps;
        char ch = '0';

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
                counter++;
            ch = 'a' - ch;
        }

        minOps = min(counter, n - counter);
        return minOps;
    }
};