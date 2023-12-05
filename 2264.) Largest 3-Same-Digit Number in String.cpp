class Solution
{
public:
    string largestGoodInteger(string a)
    {
        string maxNumber = "";
        int maxDigit = -1, n = a.size();

        for (int i = 0; i <= a.size() - 3; i++)
        {
            if (a[i] == a[i + 1] && a[i] == a[i + 2])
                maxDigit = max(maxDigit, a[i] - '0');
        }

        if (maxDigit != -1)
        {
            for (int i = 0; i < 3; i++)
                maxNumber += (maxDigit + '0');
        }

        return maxNumber;
    }
};