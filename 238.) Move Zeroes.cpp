class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int p=0,q=0;
        while(p<a.size())
        {
            if(a[p]!=0)
            {
                swap(a[p],a[q]);
                q++;
            }
            p++;
        }
    }
};