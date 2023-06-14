class Solution {
public:
    string smallestString(string s) {
        string smallStr = s;
        int start = 0, end = 0;
        while(end < s.size() && s[end] != 'a')
            end++;
        
        if(end == 0)
        {
            while(start < s.size() && s[start] == 'a')
                start++;
            
            end = start;
            while(end < s.size() && s[end] != 'a')
                end++;
        }

        if(start == end)
            smallStr[end - 1] = 'z';

        for(int i=start; i<end; i++)
            smallStr[i]--;

        return smallStr;
    }
};