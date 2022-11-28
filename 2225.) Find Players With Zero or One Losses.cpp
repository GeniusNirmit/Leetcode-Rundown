// Approach-1

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector< vector<int>> v;
        set<int> win;
        map<int,int> lose;
        for(int i=0;i<matches.size();i++)
        {
            win.insert(matches[i][0]);
            lose[matches[i][1]]++;
        }
        vector<int> temp1;
        vector<int> temp2;
        for(auto i:lose)
        {
            if(i.second == 1)
                temp2.push_back(i.first);
            if(win.find(i.first) != win.end())
                win.erase(win.find(i.first));
        }
        for(auto i:win)
            temp1.push_back(i);
        v.push_back(temp1);
        v.push_back(temp2);
        return v;
    }
};

// Approach-2

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        map<int,int> mp;
        for(int i=0;i<matches.size();i++)
        {
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
            mp[matches[i][1]]++;
        }
        vector<vector<int>> v;
        vector<int> temp1;
        vector<int> temp2;
        for(auto i:s)
        {
            if(mp[i]==1)
                temp2.push_back(i);
            else if(!mp[i])
                temp1.push_back(i);
        }
        v.push_back(temp1);
        v.push_back(temp2);
        return v;
    }
};