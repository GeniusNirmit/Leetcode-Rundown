class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& a) {
        vector<vector<int>> matrix;
        unordered_map<int, int> mp;
        int minRows = 1;
        for(int i=0; i<a.size(); i++)
            mp[a[i]]++;
        for(auto i:mp)
            minRows = max(minRows, i.second);
        
        while(minRows--)
        {
            vector<int> tuple;
            for(auto j:mp)
            {
                if(j.second > 0)
                    tuple.push_back(j.first);
                mp[j.first]--;
            }
            matrix.push_back(tuple);
        }
        return matrix;
    }
};