class Solution
{
public:
    string reverseWords(string s)
    {
        int j = 0;
        int n = s.length();
        string reversed = s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ' || i == n - 1)
            {
                int ind = i - 1;
                if (i == n - 1)
                    ind = i;
                while (j <= ind)
                {
                    swap(reversed[j], reversed[ind]);
                    ind--;
                    j++;
                }
                j = i + 1;
            }
        }
        return reversed;
    }
};