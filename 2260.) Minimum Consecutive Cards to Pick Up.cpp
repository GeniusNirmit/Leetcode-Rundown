class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<cards.size();i++)
            mp[cards[i]].insert(i);
        int min = INT_MAX;
        for(auto i:mp)
        {
            auto prev = i.second.begin();
            auto temp = prev;
            auto curr = temp++;
            while(curr != i.second.end())
            {
                if(abs(*prev-*curr) != 0 && min > abs(*prev-*curr))
                    min = abs(*prev-*curr);
                prev = curr;
                curr++;
            }
        }
        if(min != INT_MAX)
            return min+1; 
        return -1;
    }
};