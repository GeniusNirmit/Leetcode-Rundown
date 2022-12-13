class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> firstIndex;
        unordered_map<char,int> hashTable;
        for(int i=0;i<p.length();i++)
            hashTable[p[i]]++;
        int hashTableSize = hashTable.size();
        for(int i=0;i<s.length();i++)
        {
            if(hashTable.find(s[i])!=hashTable.end())
            {
                hashTable[s[i]]--;
                if(hashTable[s[i]]==0)
                    hashTableSize--;
            }
            if(i>=p.length()-1)
            {
                if(hashTableSize==0)
                    firstIndex.push_back(i-p.length()+1);
                if(hashTable.find(s[i-p.length()+1])!=hashTable.end())
                {
                    hashTable[s[i-p.length()+1]]++;
                    if(hashTable[s[i-p.length()+1]]==1)
                        hashTableSize++;
                }
            }
        }
        return firstIndex;
    }
};