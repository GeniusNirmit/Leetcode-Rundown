class Solution {
public:
    bool isPrime(int n) {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    void makePrime(int n,unordered_set<int> &primeNumberEntries) {
        for(int i=2;i<=sqrt(n);i++)
        {
            while(n%i==0)
            {
                primeNumberEntries.insert(i);
                n /= i; 
            }
        }
        if(n>2)
            primeNumberEntries.insert(n);
    }
    int distinctPrimeFactors(vector<int>& a) {
        unordered_set<int> primeNumberEntries;
        for(int i=0;i<a.size();i++)
        {
            if(isPrime(a[i]))
                primeNumberEntries.insert(a[i]);
            else
                makePrime(a[i],primeNumberEntries);
        }
        return primeNumberEntries.size();
    }
};