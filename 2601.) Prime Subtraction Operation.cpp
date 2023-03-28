class Solution {
public:
    void sieveOfEratosthenes(vector<bool> &isPrime) {
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2; i*i<=1000; i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j<=1000; j+=i)
                    isPrime[j] = false;
            }
        }
    }
    
    bool isSorted(vector<int> a) {
        for(int i=0; i<a.size()-1; i++)
        {
            if(a[i] >= a[i+1])
                return false;
        }
        return true;
    }
    
    bool primeSubOperation(vector<int>& a) {
        
        if(isSorted(a))
            return true;
        
        vector<bool> isPrime(1000, true);
        sieveOfEratosthenes(isPrime);
                
        int i = a.size()-1;
        int j = i - 1;
        
        while(j >= 0)
        {
            if(a[j] >= a[i])
            {
                for(int k = 2; k < a[j]; k++)
                {
                    if(isPrime[k] && a[j] - k < a[i])
                    {
                        a[j] -= k;
                        break;
                    } 
                }
                if(a[j] >= a[i])
                    return false;
            }
            i = j;
            j--;
        }

        return true;
    }
};