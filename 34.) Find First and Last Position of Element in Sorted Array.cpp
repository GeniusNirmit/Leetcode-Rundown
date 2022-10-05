// Approach-1

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int l=0,h=a.size()-1,mid;
        vector<int> v;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(a[mid]==target)
            {
                int temp=mid;
                while(temp>=0 && a[temp]==target)
                    temp--;
                v.push_back(temp+1);
                temp=mid;
                while(temp<=a.size()-1 && a[temp]==target)
                    temp++;
                v.push_back(temp-1);
                return v;
            }
            else if(a[mid]>target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
};