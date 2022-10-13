class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        set<int> s(a.begin(),a.end());
        int counter=0;
        for(auto i=s.begin();i!=s.end();++i)
        {
            if(!(*i <= 0) && *i != counter+1)
                return counter+1;
            else if(!(*i <= 0))
                counter++;
        }
        return counter+1;
    }
};