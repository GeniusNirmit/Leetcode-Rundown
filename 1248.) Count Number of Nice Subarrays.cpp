class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        vector<bool> isOdd(a.size(),true);
        for(int i=0;i<a.size();i++)
        {
            if(a[i]%2 == 0)
                isOdd[i] = false;
        }
        int oddCounter = 0, j = 0, counter = 0;
        for(int i=0;i<isOdd.size();i++)
        {
            if(isOdd[i])
               oddCounter++;
            if(oddCounter == k)
            {
                int ind = j;
                counter++;
                while(!isOdd[j])
                {
                    counter++;
                    j++;
                }
                j = ind;
            }
            else if(oddCounter > k)
            {
                while(oddCounter > k)
                {
                    if(isOdd[j])
                        oddCounter--;
                    j++;
                } 
                i--;
                oddCounter--;
            }
        }
        return counter;
    }
};