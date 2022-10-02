class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int carry=0;
        if(a[a.size()-1]==9)
        {
            a[a.size()-1]=0;
            carry=1;
        }
        else
            a[a.size()-1]+=1;
        for(int i=a.size()-2;i>=0;i--)
        {
            if(carry)
            {
                a[i]+=1;
                carry=0;
                if(a[i]==10)
                {
                    a[i]=0;
                    carry=1;
                }
            }
        }
        if(a[0]==0)
            a.insert(a.begin(),1);
        return a;
    }
};