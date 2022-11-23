class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, h = a.size()-1, mid;
        while(l<h)
        {
            if(a[l] < a[h])
                return a[l];
            mid = (l+h)/2;
            if(a[mid] < a[l])
                h = mid;
            else
                l = mid + 1;
        }
        return a[l];
    }
};