class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> characterMap;
        int longestCharacterReplacement = 0;
        int maxMapCharacter = 0;
        int j = 0;
        for(int i=0;i<s.length();i++)
        {
            characterMap[s[i]]++;
            if(maxMapCharacter < characterMap[s[i]])
                maxMapCharacter = characterMap[s[i]];
            if(i-j+1-maxMapCharacter > k)
            {
                characterMap[s[j]]--;
                j++;
            }
            if(longestCharacterReplacement < i-j+1)
                longestCharacterReplacement = i-j+1;
        }
        return longestCharacterReplacement;
    }
};