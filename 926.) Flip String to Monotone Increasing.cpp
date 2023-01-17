class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCounter = 0;
        int flips = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
                oneCounter++;
            else
            {
                flips++;
                flips = min(flips,oneCounter);
            }
        }
        return flips;
    }
};