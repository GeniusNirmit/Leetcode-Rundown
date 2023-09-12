class Solution
{
public:
    int minDeletions(string s)
    {
        int n = s.length();
        int counter = 0;
        vector<int> hashTable(26, 0);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            hashTable[s[i] - 'a']++;

        sort(hashTable.begin(), hashTable.end());
        for (int i = 0; i < 26; i++)
        {
            while (hashTable[i] > 0 && mp.find(hashTable[i]) != mp.end())
            {
                hashTable[i]--;
                counter++;
            }

            if (hashTable[i])
                mp[hashTable[i]]++;
        }
        return counter;
    }
};