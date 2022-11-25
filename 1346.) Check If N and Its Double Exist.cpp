// Approach-1

class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            int l = 0,h = a.size(),mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(mid != i && (a[mid] == a[i]*2.0 || a[mid] == a[i]/2.0))
                    return true;
                else if(a[mid] > a[i]*2.0 || a[mid] > a[i]/2.0)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};