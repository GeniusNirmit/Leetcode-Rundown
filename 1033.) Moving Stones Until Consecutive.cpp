class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v(2,0);
        if(max(a,max(b,c)) - min(a,min(b,c))==2)
            return v;
        set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        auto aIt = s.begin();
        auto bIt = ++aIt;
        auto cIt = ++aIt;
        aIt = s.begin();
        if(min((*cIt-*bIt),(*bIt-*aIt))<=2)
            v[0] = 1;
        else
            v[0] = 2;
        v[1] = *cIt - *aIt - 2;
        return v;
    }
};