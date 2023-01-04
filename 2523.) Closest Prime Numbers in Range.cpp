class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> closestPrimePair;
        vector<int> temp;
        vector<bool> primes(right+1,true);
        int minDiff = INT_MAX;
        primes[0] = false;
        primes[1] = false;
        for(int i=2;i*i<=right;i++)
        {
            if(primes[i])
            {
                for(int j=i*i;j<=right;j+=i)
                    primes[j] = false;
            }
        }
        for(int i=left;i<=right;i++)
        {
            if(primes[i])
            {
                temp.push_back(i);
                if(temp.size()==2)
                {
                    if(temp[1]-temp[0] < minDiff)
                    {
                        minDiff = temp[1] - temp[0];
                        closestPrimePair = temp;
                    }
                    temp.clear();
                    temp.push_back(i);
                }
            }
        }
        if(closestPrimePair.size()==0)
            return {-1,-1};
        return closestPrimePair;
    }
};