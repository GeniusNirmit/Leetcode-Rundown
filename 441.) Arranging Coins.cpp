class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1,h = n;
        long long mid;
        while(l<h)
        {
            mid = (l+h)/2;
            if(mid*(mid+1)/2 == n)
                return mid;
            else if(mid*(mid+1)/2 < n)
                l = mid + 1;
            else
                h = mid;
        }
        return l - 1;
    }
};