class Solution {
public:
    vector<bool> sieve(long long n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;   
        for(int i = 2; i <= sqrt(4e6); i++) 
        {
            if(isPrime[i]) 
            {
                for(int j = i*i; j <= 4e6; j += i) 
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }
    int diagonalPrime(vector<vector<int>>& a) {
        long long n = 4e6 + 1;
        vector<bool> isPrime = sieve(n);

        int maxVal = 0;
        for(int i=0; i<a.size(); i++)
        {
            if(isPrime[a[i][i]])
                maxVal = max(maxVal, a[i][i]);
            if(isPrime[a[i][a.size() - i - 1]])
                maxVal = max(maxVal, a[i][a.size() - i - 1]);
        }
        return maxVal;
    }
};