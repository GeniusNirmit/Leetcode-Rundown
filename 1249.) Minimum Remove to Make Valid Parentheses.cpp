class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        string valid = "";
        int counter = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                counter++;
            else if (s[i] == ')')
            {
                if (counter == 0)
                    s[i] = 'X';
                else
                    counter--;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(' && counter > 0)
            {
                s[i] = 'X';
                counter--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'X')
                valid += s[i];
        }

        return valid;
    }
};