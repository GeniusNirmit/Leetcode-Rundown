class Solution {
public:
    int addMinimum(string word) {
        string s = "abc";
        int counter = 0;
        int i = 0,j = 0;
        while(i < word.length())
        {
            if(word[i] != s[j])
                counter++;
            else
                i++;
            j++;
            j %= s.length();
        }
        if(j != 0)
            counter += (3 - j);
        return counter;
    }
};