// Finding the total prime numbers between 0 to N using Sieve of Eratosthenes.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,true);
        int counter = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(v[i])
            {
                for(int j=i*i;j<=n;j+=i)
                    v[j]=false;
            }
        }
        for(int i=2;i<n;i++)
        {
            if(v[i])   
                counter++;
        }
        return counter;
    }
};