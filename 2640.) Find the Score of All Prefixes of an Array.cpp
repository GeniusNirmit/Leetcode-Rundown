class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& a) {
        vector<long long> prefixScores(a.size());
        vector<long long> conversion(a.size());
        int maxEle = a[0];
        for(int i=0; i<a.size(); i++)
        {
            maxEle = max(a[i], maxEle);
            conversion[i] = a[i] + maxEle;
        }

        prefixScores[0] = conversion[0];
        for(int i=1; i<a.size(); i++)
            prefixScores[i] = prefixScores[i-1] + conversion[i];
        
        return prefixScores;
    }
};