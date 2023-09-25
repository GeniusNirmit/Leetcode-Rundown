class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int oneCounter = 0, n = s.length();
        string maxNumber = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                oneCounter++;
        }

        int i = 0;
        while (i < oneCounter - 1)
        {
            maxNumber += "1";
            i++;
        }

        i = 0;
        while (i < n - oneCounter)
        {
            maxNumber += '0';
            i++;
        }

        maxNumber += '1';
        return maxNumber;
    }
};