class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int l = 0,h = a.size()-1, mid;
        while(l<h)
        {
            mid = (l+h)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
                return mid;
            else if(a[mid]>a[mid-1])
                l = mid;
            else    
                h = mid + 1;
        }
        return 0;
    }
};