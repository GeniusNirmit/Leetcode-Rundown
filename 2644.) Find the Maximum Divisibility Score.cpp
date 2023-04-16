class Solution {
public:
    int maxDivScore(vector<int>& a, vector<int>& divisors) {
        int maxCounter = -1;
        int maxDivisor = 0;
        for(int i=0; i<divisors.size(); i++)
        {
            int counter = 0;
            for(int j=0; j<a.size(); j++)
            {
                if(a[j] % divisors[i] == 0)
                    counter++;
            }
            if(counter > maxCounter)
            {
                maxDivisor = divisors[i];
                maxCounter = counter;
            }
            else if(counter == maxCounter)
                maxDivisor = min(maxDivisor, divisors[i]);
        }
        return maxDivisor;
    }
};