class Solution {
public:
    int maxVowels(string s, int k) {
        int counter=0, max=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                counter++;
        }
        max = counter;
        for(int i=k;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                counter++;
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
                counter--;
            if(counter > max)
                max = counter;
        }
        return max;
    }
};