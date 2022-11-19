// Approach-1

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        k %= a.size();
        reverse(a.begin(),a.begin()+a.size()-k);
        reverse(a.begin()+a.size()-k,a.end());
        reverse(a.begin(),a.end());
    }
};

// Approach-2

    class Solution 
    {
    public:
        void rotate(vector<int> a, int k) 
        {
            if(a.size()==0 || k<=0)
                return;
            vector<int> v;
            for(int i=0;i<a.size();i++)
                v.push_back(a[i]);
            for(int i=0;i<a.size();i++)
                a[(i+k)%a.size()] = v[i];
        }
    };