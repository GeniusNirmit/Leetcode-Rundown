// Approach-1

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        vector<int> v;
        int l=0,h=0;
        for(h=0;h<a.size();h++)
        {
            if(a[h]>=0)
                break;
        }
        int temp=h;
        l=h-1;
        while(l>=0 && h<a.size())
        {
            if(-a[l]<a[h])
            {
                v.push_back(a[l]);
                l--;
            }
            else
            {
                v.push_back(a[h]);
                h++;
            }
        }
        while(l>=0)
        {
            v.push_back(a[l]);
            l--;
        }
        while(h<a.size())
        {
            v.push_back(a[h]);
            h++;
        }
        for(int i=0;i<v.size();i++)
            v[i]=v[i]*v[i];
        return v;
    }
};

// Approach-2

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        for(int i=0;i<a.size();i++)
            a[i] = a[i]*a[i];
        sort(a.begin(),a.end());
        return a;
    }
};