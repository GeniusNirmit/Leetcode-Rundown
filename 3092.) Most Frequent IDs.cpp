class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& a, vector<int>& freq) {
        int n = a.size();
        
        vector<long long> mostFrequent(n);
        map<long long, long long> mp;
        map<long long, long long, greater<long long>> freqMp;
        
        for(int i = 0; i < n; i++)
        {
            freqMp[mp[a[i]]]--;
            if(freqMp[mp[a[i]]] == 0)
                freqMp.erase(mp[a[i]]);
            
            mp[a[i]] += freq[i];
            freqMp[mp[a[i]]]++;
            
            mostFrequent[i] = freqMp.begin()->first;
        }
        
        return mostFrequent;
    }
};