class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        string reversed = s;
        string palindrome;
        reverse(reversed.begin(), reversed.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLength = 0;
        pair<int, int> maxLengthInd;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == reversed[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

                if (maxLength < dp[i][j])
                {
                    string current = s.substr(i - dp[i][j], dp[i][j]);
                    string currentReversed = current;
                    reverse(currentReversed.begin(), currentReversed.end());

                    if (current == currentReversed)
                    {
                        maxLength = dp[i][j];
                        palindrome = current;
                    }
                }
            }
        }

        return palindrome;
    }
};