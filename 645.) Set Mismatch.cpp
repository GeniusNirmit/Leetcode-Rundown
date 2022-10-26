class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        vector<int> hash_table(a.size()+1,0);
        vector<int> v;
        for(int i=0;i<a.size();i++)
            hash_table[a[i]]++;
        for(int i=1;i<hash_table.size();i++)
        {
            if(hash_table[i]>1)
                v.push_back(i);
        }
        for(int i=1;i<hash_table.size();i++)
        {
            if(hash_table[i]==0)
                v.push_back(i);
        }
        return v;
    }
};