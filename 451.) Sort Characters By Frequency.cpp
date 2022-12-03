class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b) {
        return a.second > b.second;   
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> v;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        for(auto i:mp)
            v.push_back(i);
        sort(v.begin(),v.end(),cmp);
        s = "";
        for(auto i:v)
        {
            while(i.second--)
                s += i.first;
        }
        return s;
    }
};