class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        return replace(n, k);
    }
    int replace(int n, int k)
    {
        if (n == 1)
            return 0;

        int half = pow(2, (n - 2));

        if (k > half)
            return 1 - kthGrammar(n, k - half);

        return replace(n - 1, k);
    }
};