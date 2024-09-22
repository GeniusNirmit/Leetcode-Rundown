class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.length();
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        string temp = s + "-" + reversed;
        int m = temp.length();
        vector<int> lps(m, 0);

        int prev = 0, current = 1;

        while (current < m)
        {
            if (temp[current] == temp[prev])
            {
                lps[current] = prev + 1;
                current++;
                prev++;
            }
            else if (prev == 0)
            {
                lps[current] = 0;
                current++;
            }
            else
                prev = lps[prev - 1];
        }

        return reversed.substr(0, n - lps[m - 1]) + s;
    }
};