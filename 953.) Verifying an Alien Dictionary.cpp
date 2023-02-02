class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> lexioOrder;
        for(int i=0;i<order.length();i++)
            lexioOrder[order[i]] = i;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j >= words[i+1].length())
                    return false;
                if(words[i][j] != words[i+1][j])
                {
                    if(lexioOrder[words[i][j]] > lexioOrder[words[i+1][j]])
                        return false;
                    else
                        break;
                }
            }
        }
        return true;
    }
};