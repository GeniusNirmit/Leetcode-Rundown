class Solution
{
public:
    int countHomogenous(string s)
    {
        int MOD = 1e9 + 7;
        int n = s.length();
        long long counter = 0, currentCounter = 1;
        char prev = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] != prev)
            {
                counter = counter + (((currentCounter * (currentCounter + 1)) / 2) % MOD);
                currentCounter = 1;
                prev = s[i];
            }
            else
                currentCounter++;
        }

        counter = counter + (((currentCounter * (currentCounter + 1)) / 2) % MOD);
        return counter;
    }
};