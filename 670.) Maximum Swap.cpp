class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr = to_string(num);
        int n = numStr.length();
        int maxInd = -1;
        int swapInd1 = -1, swapInd2 = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (maxInd == -1 || numStr[i] > numStr[maxInd])
                maxInd = i;
            if (numStr[i] < numStr[maxInd])
            {
                swapInd1 = i;
                swapInd2 = maxInd;
            }
        }

        if (swapInd1 != -1 && swapInd2 != -1)
            swap(numStr[swapInd1], numStr[swapInd2]);

        return stoi(numStr);
    }
};