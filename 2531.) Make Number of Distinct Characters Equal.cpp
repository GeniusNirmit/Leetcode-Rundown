class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> word1Map;
        unordered_map<char,int> word2Map;

        for(int i=0;i<word1.size();i++)
            word1Map[word1[i]]++;
        for(int i=0;i<word2.size();i++)
            word2Map[word2[i]]++;

        for(auto i:word1Map)
        {
            for(auto j:word2Map)
            {
                unordered_map<char,int> temp1 = word1Map;
                unordered_map<char,int> temp2 = word2Map;

                temp2[i.first]++;
                temp1[j.first]++;

                temp1[i.first]--;
                temp2[j.first]--;

                if(temp1[i.first]==0)
                    temp1.erase(i.first);
                if(temp2[j.first]==0)
                    temp2.erase(j.first);
                if(temp1.size()==temp2.size())
                    return true;
            }
        }
        return false;
    }
};