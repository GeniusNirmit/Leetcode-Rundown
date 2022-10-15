class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0,h=a.size()-1,mid;
        while(l<=h)
        {
            mid = l + (h-l)/2;
            if(target == a[mid])
                return mid;
            else if(a[mid] >= a[l])
            {
                if(a[l]<=target && a[mid]>=target)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else 
            {
                if(a[h]>=target && a[mid]<=target)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};