class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        while(i<haystack.length())
        {
            if(needle == haystack.substr(i,needle.length()))
                return i;
            i++;
        }
        return -1;
    }
};