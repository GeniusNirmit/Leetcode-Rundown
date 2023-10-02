class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.length();
        int aCounter = 0, bCounter = 0;
        int start = 0, end = 0;
        while (end != n)
        {
            while (colors[start] == colors[end])
                end++;
            if (colors[start] == 'A' && end - start > 2)
                aCounter += end - start - 2;
            else if (colors[start] == 'B' && end - start > 2)
                bCounter += end - start - 2;
            start = end;
        }

        return aCounter > bCounter;
    }
};