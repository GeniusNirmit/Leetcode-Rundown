class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int counter = 0;
        long long product = 1;
        int l = 0,h = 0;
        while(h<a.size())
        {
            product *= a[h];
            while(product>=k && l<=h)
            {
                product /= a[l];
                l++;
            }
            counter += (h-l)+1;
            h++;
        }
        return counter;
    }
};