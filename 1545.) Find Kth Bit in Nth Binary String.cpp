class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';

        int len = pow(2, n) - 1;
        bool invert = false;

        while (k > 1)
        {
            int mid = (len + 1) / 2;

            if (k == mid)
            {
                if (invert)
                    return '0';
                else
                    return '1';
            }

            if (k > mid)
            {
                k = len - k + 1;
                invert = !invert;
            }

            len /= 2;
        }

        if (invert)
            return '1';
        return '0';
    }
};