class Solution
{
public:
    int findComplement(int num)
    {
        int complement = 0, i = 0;

        while (num > 0)
        {
            int temp = num % 2;
            if (temp == 0)
                complement += pow(2, i);

            i++;
            num /= 2;
        }

        return complement;
    }
};