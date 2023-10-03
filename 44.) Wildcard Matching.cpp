class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();

        vector<bool> prev(n + 1, false);
        prev[0] = true;

        bool flag = true;
        for (int i = 1; i <= m; i++)
        {
            vector<bool> current(n + 1, false);
            for (int j = 1; j <= i; j++)
            {
                if (p[i - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            current[0] = flag;

            for (int j = 1; j <= n; j++)
            {
                if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
                    current[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                    current[j] = prev[j] | current[j - 1];
                else
                    current[j] = false;
            }
            prev = current;
        }
        return prev[n];
    }
};