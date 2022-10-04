class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter=0;
        int l=s.length()-1;
        while(l>=0 && s[l]==' ')
            l--;
        while(l>=0 && s[l]!=' ')
        {
            counter++;
            l--;
        }
        return counter;
    }
};