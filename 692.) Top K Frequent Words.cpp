class Solution {
public:
    static bool cmp(pair<string,int> &a, pair<string,int> &b)
    {
        if(a.second > b.second)
            return true;
        if(a.second==b.second && a.first<b.first)
            return true;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> v;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        vector<pair<string, int>> temp;
        for(auto i:mp)
            temp.push_back(i);
        sort(temp.begin(),temp.end(),cmp);
        for(auto i:temp)
        {
            if(k-->0)
                v.push_back(i.first);
        }
        return v;
    }
};