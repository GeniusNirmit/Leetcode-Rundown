class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int l=0,h=a.size()-1,mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(a[mid]==target)
                return mid;
            else if(a[mid]>target)
                h=mid-1;
            else
                l=mid+1;
        }
        if(a[mid]<target)
            return mid+1;
        else
            return mid;
    }
};