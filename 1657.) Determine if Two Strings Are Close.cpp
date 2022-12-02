class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        unordered_set<char> s(word1.begin(),word1.end());
        vector<int> hashtable1(26,0);
        vector<int> hashtable2(26,0);
        for(int i=0;i<word2.length();i++)
        {
            if(s.find(word2[i]) == s.end())
                 return false;
            hashtable2[word2[i]-'a']++;
        }
        for(int i=0;i<word1.length();i++)
            hashtable1[word1[i]-'a']++;
        sort(hashtable1.begin(),hashtable1.end());
        sort(hashtable2.begin(),hashtable2.end());
        for(int i=0;i<hashtable1.size();i++)
        {
            if(hashtable1[i] != hashtable2[i])
                return false;
        }
        return true;
    }
};