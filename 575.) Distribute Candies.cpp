// Approach-1

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        for(int i=0;i<candyType.size();i++)
            mp[candyType[i]]++;
        if(candyType.size()/2 > mp.size())
            return mp.size();
        return candyType.size()/2;
    }
};

// Approach-2

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(),candyType.end());
        if(candyType.size()/2 > s.size())
            return s.size();
        return candyType.size()/2;
    }
};