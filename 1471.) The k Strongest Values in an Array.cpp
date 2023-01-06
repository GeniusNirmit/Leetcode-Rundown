class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        if(a.size()==1)
            return {a[0]};
        sort(a.begin(),a.end());
        int mid = a[(a.size()-1)/2];
        vector<int> strongestArray;
        int p = 0, q = a.size()-1;
        for(int i=0;i<k;i++)
        {
            if(abs(a[p]-mid)<=abs(a[q]-mid))
            {
                strongestArray.push_back(a[q]);
                q--;
            }
            else
            {
                strongestArray.push_back(a[p]);
                p++;
            }
        }
        return strongestArray;
    }
};