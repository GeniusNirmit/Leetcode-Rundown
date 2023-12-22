class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                    minCost = min(minCost, 1 + dp[j + 1]);
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};