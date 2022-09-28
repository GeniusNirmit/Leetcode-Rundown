class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int product=1;
        vector<int> v;
        for(int i=0;i<a.size();i++)
        {
            v.push_back(product);
            product*=a[i];
        }
        product=1;
        for(int i=a.size()-1;i>=0;i--)
        {
            v[i]*=product;
            product*=a[i];
        }
        return v;
    }
};