class Solution {
public:
    vector<vector<long long>> nCr;
    long long mod=1e9+7;

    int numOfWays(vector<int>& a) {
        nCr.resize(a.size() + 1);
        for(int i=0; i<a.size()+1; i++)
        {
            nCr[i] = vector<long long>(i + 1, 1);
            for(int j=1; j<i; j++)
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % mod;
        }
        return ( ways(a, a.size()) - 1) % mod;
    }

    long long ways(vector<int>& a, int size) {
        if(size <= 2)
            return 1;
        
        vector<int> left;
        vector<int> right;
        for(int i=1; i<size; i++)
        {
            if(a[0] > a[i])
                left.push_back(a[i]);
            else 
                right.push_back(a[i]);
        }
        long long leftWays = ways(left, left.size());
        long long rightWays = ways(right, right.size());

        long long totalWays = ((( nCr[a.size() - 1][left.size()] * leftWays) % mod) * rightWays) % mod;
        
        return totalWays;
    }
};