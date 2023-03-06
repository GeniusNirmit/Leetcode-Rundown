class Solution {
public:
    int subarrayGCD(vector<int>& a, int k) {
        int counter = 0;
        for(int i=0;i<a.size();i++)
        {
            int gcd = 0;
            for(int j=i;j<a.size();j++)
            {
                gcd = __gcd(gcd, a[j]);
                if(gcd == k)
                    counter++;
            }
        }
        return counter;
    }
};