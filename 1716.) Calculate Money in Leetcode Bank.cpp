class Solution
{
public:
    int totalMoney(int n)
    {
        if (n < 7)
            return (n * (n + 1) / 2);

        int counter = 0;
        int total = 28;
        int iterations = n / 7;

        for (int i = 0; i < iterations; i++)
            counter += (total + i * 7);

        for (int i = 0; i < n % 7; i++)
            counter += (iterations + 1) + i;
        return counter;
    }
};