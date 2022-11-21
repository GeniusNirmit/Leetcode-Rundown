class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,int> mp;
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<mat.size();i++)
        {
            int l = 0,h = mat[0].size()-1,mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(mat[i][mid] == 1)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            mp[i]=l;
        }
        for(auto i:mp)
            s.insert(i.second);
        auto i = s.begin();
        while(k--)
        {
            for(auto it:mp)
            {
                if(it.second == *i)
                {
                    v.push_back(it.first);
                    mp.erase(it.first);
                    break;
                }
            }
            i++;   
        }
        return v;
    }
};