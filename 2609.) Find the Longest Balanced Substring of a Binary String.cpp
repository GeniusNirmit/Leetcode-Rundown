class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zeroCount = 0, maxSize = 0;
        for(int i=0;i<s.length();i++)
        {
            int j=i;
            while(j<s.length() && s[j]=='0')
            {
                zeroCount++;
                j++;
            }
            while(j<s.length() && s[j]=='1')
            {
                if(zeroCount > 0)
                {
                    zeroCount--;
                    j++;
                }
                else        
                    break;
            }
            if(zeroCount==0)
                maxSize = max(maxSize, j - i);
            else
                zeroCount = 0;
        }
        return maxSize;
    }
     
};