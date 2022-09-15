class Solution {
public:
    int singleNumber(vector<int>& a) {
        if(a.size()==1)
            return a[0];
        else
        {
            sort(a.begin(),a.end());
            if(a[0]!=a[1])
                return a[0];
            for(int i=0;i<a.size()-2 && a.size();i++)
            {
                if(a[i]!=a[i+1] && a[i+1]!=a[i+2])
                    return a[i+1];
            }
            return a[a.size()-1];
        }
    }
};