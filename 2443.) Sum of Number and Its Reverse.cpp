class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0)
            return true;
        for(int i=1;i<=num;i++)
        {
            int sum=i;
            string number;
            int temp=i;
            while(temp>0)
            {
                char x = '0'+(temp%10);
                number += x;
                temp/=10;
            }
            int n=stoi(number);
            sum+=n;
            if(sum==num)
            {
                return true;
            }
        }
        return false;
    }
};