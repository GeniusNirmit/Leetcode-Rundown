class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> characterMap;
        int counter = 0;
        int j = 0;
        for(int i=0;i<s.length();i++)
        {
            characterMap[s[i]]++;
            while(characterMap['a'] && characterMap['b'] && characterMap['c'])
            {
                counter += (s.length()-i);
                characterMap[s[j]]--;
                j++;
            }
        }
        return counter;
    }
};