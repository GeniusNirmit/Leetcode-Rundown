class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int counter = 0;
        while(temp)
        {
            if(num%(temp%10)==0)
                counter++;
            temp/=10;
        }
        return counter;
    }
};