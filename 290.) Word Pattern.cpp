class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> stringWords;
        string tempWord="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                stringWords.push_back(tempWord);
                tempWord="";
            }
            else
                tempWord = s[i] + tempWord;
        }
        stringWords.push_back(tempWord);
        if(pattern.length()!=stringWords.size())
            return false;
        unordered_map<char,string> charToString; 
        unordered_map<string,char> stringToChar;
        for(int i=0;i<stringWords.size();i++)
        {
            if(charToString.find(pattern[i])==charToString.end())
                charToString[pattern[i]] = stringWords[i];
            if(stringToChar.find(stringWords[i])==stringToChar.end())
                stringToChar[stringWords[i]] = pattern[i];
            if(charToString[pattern[i]] != stringWords[i] || stringToChar[stringWords[i]] != pattern[i])
                return false;
        }
        return true;
    }
};