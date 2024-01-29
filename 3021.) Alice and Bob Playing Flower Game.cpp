class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long oddX = 0, oddY = 0, evenX = 0, evenY = 0;

        evenX = n / 2;
        if (n % 2 == 0)
            oddX = evenX;
        else
            oddX = evenX + 1;
        evenY = m / 2;
        if (m % 2 == 0)
            oddY = evenY;
        else
            oddY = evenY + 1;

        return evenX * oddY + oddX * evenY;
    }
};