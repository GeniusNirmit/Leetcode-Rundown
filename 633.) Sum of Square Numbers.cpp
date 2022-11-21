// Approach-1

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++)
        {
            long long l = 0,h = sqrt(c),mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if((i*i) + (mid*mid) == c)
                    return true;
                else if((i*i) + (mid*mid) > c)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};

// Approach-2

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long p = 0,q = sqrt(c);
        while(p<=q)
        {
            long long temp = (p*p)+(q*q);
            if(temp == c)
                return true;
            else if(temp > c)
                q--;
            else
                p++;
        }
        return false;
    }
};