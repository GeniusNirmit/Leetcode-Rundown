class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> givenAnagramString;
        unordered_map<char,int> findAnagramString;
        for(int i=0;i<s.length();i++)
            givenAnagramString[s[i]]++;
        for(int i=0;i<t.length();i++)
            findAnagramString[t[i]]++;
        if(givenAnagramString.size()!=findAnagramString.size())
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(givenAnagramString[s[i]]!=findAnagramString[s[i]])
                return false;
        }
        return true;
    }
};