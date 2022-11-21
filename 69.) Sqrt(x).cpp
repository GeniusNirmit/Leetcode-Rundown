class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        long long mid;
        int temp;
        while(l <= h)
        {
            mid = (l+h)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid > x)
                h = mid - 1;
            else 
            {
                temp = mid;
                l = mid + 1;
            }
        }
        return temp;
    }
};