class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long lastElement = x;

        while (--n)
            lastElement = (lastElement + 1) | x;

        return lastElement;
    }
};