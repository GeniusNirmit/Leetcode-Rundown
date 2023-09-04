class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.length();
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            vector<int> current(n + 1, 0);
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == reversed[j - 1])
                    current[j] = 1 + prev[j - 1];
                else
                    current[j] = max(current[j - 1], prev[j]);
            }
            prev = current;
        }

        return n - prev[n];
    }
};