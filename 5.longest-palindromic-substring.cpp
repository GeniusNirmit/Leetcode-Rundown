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
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (maxLength < dp[i][j])
                    {
                        maxLength = dp[i][j];
                        maxLengthInd = {i, j};
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        int i = maxLengthInd.first, j = maxLengthInd.second;
        // while (dp[i][j] != 0)
        // {
        //     palindrome = palindrome + s[i - 1];
        //     i--;
        //     j--;
        // }
        // return palindrome;

        return s.substr(i, j + 1);
    }
};