class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<set<char>> uniqueWords;
        for(int i=0;i<words.size();i++)
        {
            set<char> temp(words[i].begin(),words[i].end());
            uniqueWords.push_back(temp);
        }
        int counter = 0;
        for(int i=0;i<uniqueWords.size();i++)
        {
            for(int j=0;j<uniqueWords.size();j++)
            {
                if(i!=j && uniqueWords[i]==uniqueWords[j])
                    counter++;
            }
        }
        return counter/2;
    }
};