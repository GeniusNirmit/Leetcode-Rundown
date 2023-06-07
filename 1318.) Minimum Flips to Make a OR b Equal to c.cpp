class Solution {
public:
    int minFlips(int a, int b, int c) {
        int maxLength = max(log2(a), max( log2(b), log2(c))) + 1;
        int counter = 0;
        string binA = convertToBinary(a, maxLength);
        string binB = convertToBinary(b, maxLength);
        string binC = convertToBinary(c, maxLength);

        for(int i=0; i<maxLength; i++)
        {
            if((binC[i] - '0') == 1)
            {
                if((binA[i] - '0') == 0 && (binB[i] - '0') == 0)
                    counter++;
            }
            else
                counter += (binA[i] - '0') + (binB[i] - '0');
        }
        return counter;
    }
    string convertToBinary(int num, int maxLength) {
        string binary;
        while(num)
        {
            binary.push_back(num % 2 + '0');
            num /= 2;
        }
        while(binary.length() != maxLength)
            binary.push_back('0');
        reverse(binary.begin(), binary.end());
        return binary;
    }
};