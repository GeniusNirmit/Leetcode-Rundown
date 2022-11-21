// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 0,h = n, mid;
        long long bad = 0;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(isBadVersion(mid))
            {
                bad = mid;
                h = mid - 1;
            }
            else 
                l = mid + 1;
        }
        return bad;
    }
};