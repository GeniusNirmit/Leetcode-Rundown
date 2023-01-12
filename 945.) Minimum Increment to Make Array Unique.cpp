class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        sort(a.begin(),a.end());
        int counter = 0;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i] >= a[i+1])
            {
                counter = counter + (a[i]-a[i+1]) + 1;
                a[i+1] = a[i] + 1;
            }
        }
        return counter;
    }
};