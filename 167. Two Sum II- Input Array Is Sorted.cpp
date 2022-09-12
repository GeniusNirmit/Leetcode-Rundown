class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> v;
        for(int i=0;i<a.size();i++)
        {
            int l=i+1,h=a.size()-1,mid;
            while(l<=h)
            {
                mid=(l+h)/2;
                if(a[mid]==(target-a[i]))
                {
                    v.push_back(i+1);
                    v.push_back(mid+1);
                    break;
                }
                else if(a[mid]>(target-a[i]))
                    h=mid-1;
                else
                    l=mid+1;
            }
        }
        return v;
    }
};