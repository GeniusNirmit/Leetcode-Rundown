class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        vector<int> frequentElements;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        vector<pair<int,int>> mpToPair;
        for(auto i:mp)
            mpToPair.push_back(i);
        sort(mpToPair.begin(),mpToPair.end(),cmp);
        auto i = mpToPair.begin();
        while(k--)
        {
            frequentElements.push_back(i->first);
            i++;
        }
        return frequentElements;
    }
};