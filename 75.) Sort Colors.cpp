class Solution {
public:
    void sortColors(vector<int>& a) {
        int l = 0,mid = 0, h = a.size()-1;
        while(mid<=h)
        {
            if(a[mid] == 0)
            {
                swap(a[l],a[mid]);
                l++;
                mid++;
            }
            else if(a[mid] == 1)
                mid++;
            else
            {
                swap(a[h],a[mid]);
                h--;
            }
        }
    }
};