    class Solution {
public:
    int findPeakElement(vector<int>& a) {
        if(a.size()==1 || a[0] > a[1])
            return 0;
        if(a[a.size()-1] > a[a.size()-2])
            return a.size()-1;
        int l = 0,h = a.size()-1, mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(a[mid] > a[mid+1] && a[mid] > a[mid-1])
                return mid;
            else if(a[mid] < a[mid+1])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return 0;
    }
};