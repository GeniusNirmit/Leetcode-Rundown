class Solution
{
public:
    int minOperations(int k)
    {
        if (k == 1)
            return 0;

        int num = 1, sum = 1;
        int counter = INT_MAX;
        while (num <= k)
        {
            int currentCounter = num + (k / num);
            if (k % num != 0)
                currentCounter++;

            counter = min(counter, currentCounter);
            num++;
        }

        return counter - 2;
    }
};