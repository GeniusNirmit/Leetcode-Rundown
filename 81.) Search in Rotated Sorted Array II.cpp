class Solution {
public:
    bool search(vector<int>& a, int target) {
        int l=0,h=a.size()-1,mid;
        while(l<=h)
        {
            mid = (h+l)/2;
            if(target == a[mid])
                return true;
            else if(a[mid] == a[l] && a[mid] == a[h])
            {
                l++;
                h--;
            }
            else if(a[mid] >= a[l])
            {
                if(a[l]<=target && a[mid]>target)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else 
            {
                if(a[h]>=target && a[mid]<target)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }
};