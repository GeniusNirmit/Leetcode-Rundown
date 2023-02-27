class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& a) {
        sort(a.begin(),a.end());
        int l = 0, h = (a.size()+1)/2;
        int counter = 0;
        while(h < a.size())
        {
            if(a[l]*2 <= a[h])
            {
                l++;
                counter += 2;
            }
            h++;
        }
        return counter;
    }
};