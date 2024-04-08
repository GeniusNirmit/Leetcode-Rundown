// Solution - 1

class Solution
{
    int checkValidity(string s, int ind, int counter, vector<vector<int>> &dp)
    {
        int n = s.length();

        if (ind == n)
        {
            if (counter == 0)
                return true;
            return false;
        }

        if (dp[ind][counter] != -1)
            return dp[ind][counter];

        bool flag = false;

        if (s[ind] == '(')
            return dp[ind][counter] = checkValidity(s, ind + 1, counter + 1, dp);
        else if (s[ind] == ')' && counter > 0)
            return dp[ind][counter] = checkValidity(s, ind + 1, counter - 1, dp);
        else if (s[ind] == '*')
        {
            flag |= checkValidity(s, ind + 1, counter + 1, dp);
            flag |= checkValidity(s, ind + 1, counter, dp);

            if (counter > 0)
                flag |= checkValidity(s, ind + 1, counter - 1, dp);
        }

        return dp[ind][counter] = flag;
    }

public:
    bool checkValidString(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return checkValidity(s, 0, 0, dp);
    }
};

// Solution - 2

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();
        int openCounter = 0, closeCounter = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*')
                openCounter++;
            else
                openCounter--;

            if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
                closeCounter++;
            else
                closeCounter--;

            if (closeCounter < 0 || openCounter < 0)
                return false;
        }

        return true;
    }
};