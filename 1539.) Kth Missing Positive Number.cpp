class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int l = 0,h = a.size()-1, mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(a[mid] - mid - 1 < k)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l + k;
    }
};