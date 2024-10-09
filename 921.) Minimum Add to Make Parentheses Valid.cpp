class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int counter = 0;
        int bracketCounter = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                bracketCounter++;
            else
            {
                if (bracketCounter > 0)
                    bracketCounter--;
                else
                    counter++;
            }
        }

        return counter + bracketCounter;
    }
};