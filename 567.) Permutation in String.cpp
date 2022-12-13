class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> hashTable;
        for(int i=0;i<s1.length();i++)
            hashTable[s1[i]]++;
        int hashTableSize = hashTable.size();
        for(int i=0;i<s2.length();i++)
        {
            if(hashTable.find(s2[i])!=hashTable.end())
            {
                hashTable[s2[i]]--;
                if(hashTable[s2[i]]==0)
                    hashTableSize--;
            }
            if(i>=s1.length()-1)
            {
                if(hashTableSize==0)
                    return true;
                if(hashTable.find(s2[i-s1.length()+1])!=hashTable.end())
                {
                    hashTable[s2[i-s1.length()+1]]++;
                    if(hashTable[s2[i-s1.length()+1]]==1)
                        hashTableSize++;
                }
            }
        }
        return false;
    }
};