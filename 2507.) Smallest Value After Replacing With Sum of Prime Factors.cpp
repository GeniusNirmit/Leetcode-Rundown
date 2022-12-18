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
    int makePrime(int n) {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                if(isPrime(i) && isPrime(n/i))
                    return i+(n/i);
                else if(!isPrime(i) && isPrime(n/i))
                {
                    int temp = makePrime(i);
                    return temp+(n/i);
                }
                else if(isPrime(i) && !isPrime(n/i))
                {
                    int temp = makePrime(n/i);
                    return temp+i; 
                }
                else if(!isPrime(i) && !isPrime(n/i))
                {
                    int temp1 = makePrime(i);
                    int temp2 = makePrime(n/i);
                    return temp1+temp2;
                }
            }
        }
        return 0;
    }
    int smallestValue(int n) {
        while(!isPrime(n))
        {
            int temp = makePrime(n);
            if(temp==n)
                return n;
            else
                n = temp;
        }
        return n;
    }
};