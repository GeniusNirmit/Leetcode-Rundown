class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>s;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string st = strs[i];
            sort(st.begin(),st.end());
            mp[st].push_back(strs[i]);
        }
        for(auto i:mp)
            s.push_back(i.second);
        return s;
    }
};