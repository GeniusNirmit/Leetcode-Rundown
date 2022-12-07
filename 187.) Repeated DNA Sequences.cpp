class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mp;
        string temp;
        int i=0;
        while(i<=s.length())
        {
            if(i>=10)
            {
                mp[temp]++;
                temp.erase(temp.begin());
            }
            temp += s[i];
            i++;
        }
        for(auto i:mp)
        {
            if(i.second>=2)
                v.push_back(i.first);
        }
        return v;
    }
};