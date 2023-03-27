class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        while(k--)
        {
            if(numOnes)
            {
                sum++;
                numOnes--;
            }
            else if(numZeros)
                numZeros--;
            else if(numNegOnes)
            {
               sum--;
                numNegOnes--;
            }
        }
        return sum;
    }
};