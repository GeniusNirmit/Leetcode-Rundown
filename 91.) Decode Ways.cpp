class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return decodeString(n, s, 0, dp);
    }
    int decodeString(int &n, string &s, int ind, vector<int> &dp)
    {
        if (ind == n)
            return 1;
        if (ind > n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        if (s[ind] == '0')
            return dp[ind] = 0;

        int singleChar = 0, doubleChar = 0;
        if (stoi(s.substr(ind, 2)) <= 26)
        {
            singleChar = decodeString(n, s, ind + 1, dp);
            doubleChar = decodeString(n, s, ind + 2, dp);
        }
        else
            singleChar = decodeString(n, s, ind + 1, dp);

        return dp[ind] = singleChar + doubleChar;
    }
};