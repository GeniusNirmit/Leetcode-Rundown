class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int n = a + b + c;
        string str = "";
        int aCounter = 0, bCounter = 0, cCounter = 0;

        for (int i = 0; i < n; i++)
        {
            if ((a >= b && a >= c && aCounter < 2) || (a > 0 && (bCounter == 2 || cCounter == 2)))
            {
                str += 'a';
                a--;
                aCounter++;
                bCounter = 0;
                cCounter = 0;
            }
            else if ((b >= a && b >= c && bCounter < 2) || (b > 0 && (cCounter == 2 || aCounter == 2)))
            {
                str += 'b';
                b--;
                aCounter = 0;
                bCounter++;
                cCounter = 0;
            }
            else if ((c >= a && c >= b && cCounter < 2) || (c > 0 && (aCounter == 2 || bCounter == 2)))
            {
                str += 'c';
                c--;
                aCounter = 0;
                bCounter = 0;
                cCounter++;
            }
        }

        return str;
    }
};