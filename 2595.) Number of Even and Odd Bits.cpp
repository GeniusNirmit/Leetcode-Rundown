class Solution {
public:
    vector<int> decimalToBinary(int n)
    {
        vector<int> binaryNumber(32);
        while(n>0) 
        {
            binaryNumber.push_back(n%2);
            n /= 2;
        }
        return binaryNumber;
    }
    vector<int> evenOddBit(int n) {
        vector<int> binaryNumber = decimalToBinary(n);
        vector<int> evenOdd(2,0);
        for(int i=0;i<binaryNumber.size();i++)
        {
            if(binaryNumber[i]==1 && i%2==0)
                evenOdd[0]++;
            else if(binaryNumber[i]==1 && i%2==1)
                evenOdd[1]++;
        }
        return evenOdd;
    }
};