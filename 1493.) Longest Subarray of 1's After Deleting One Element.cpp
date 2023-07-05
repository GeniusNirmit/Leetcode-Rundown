class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int i=0, j=0, maxSize = INT_MIN, counter = 0;
        while(j < a.size())
        {
            if(a[j] == 0)
                counter++;
            while(counter > 1)
            {
                if(a[i] == 0)
                    counter--;
                i++;
            }
            maxSize = max(maxSize, j - i);
            j++;
        }
        
        if(maxSize == INT_MIN)
            return j - i - 1;
        return maxSize;
    }
};