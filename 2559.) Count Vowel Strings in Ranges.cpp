class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> allQueries;
        vector<int> givenQueries;
        string allVowels = "aeiou";
        unordered_set<char> vowels(allVowels.begin(),allVowels.end());
        for(int i=0;i<words.size();i++)
        {
            string word = words[i];
            if(vowels.find(word[0])!=vowels.end() && vowels.find(word[word.length()-1])!=vowels.end())
            {
                if(i)
                    allQueries.push_back(allQueries[i-1]+1);
                else
                    allQueries.push_back(1);
            }
            else
            {
                if(i)
                    allQueries.push_back(allQueries[i-1]);
                else
                    allQueries.push_back(0);   
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            if(!queries[i][0])
                givenQueries.push_back(allQueries[queries[i][1]]);
            else
                givenQueries.push_back(allQueries[queries[i][1]] - allQueries[queries[i][0]-1]);
        }
        return givenQueries;
    }
};