class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.length();
        int counter = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
                counter++;
            else if (counter > 0)
                counter--;
        }

        return (counter + 1) / 2;
    }
};