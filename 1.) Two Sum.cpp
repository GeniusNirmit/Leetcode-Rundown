class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> v;
        int i,j,counter=0;
        for(i=0;i<a.size();i++)
        {
            for(j=0;j<a.size();j++)
            {
                if(a[i]+a[j]==target && !counter  && i!=j)
                {
                    counter=1;
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};