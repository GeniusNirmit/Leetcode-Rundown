class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        while(n) 
        {
            if(n%2)
            {
                if(n>0)
                    answer *= x;
                else
                    answer /=  x;
            }
            x*=x;
            n/=2;
        }
        return answer;
    }
};