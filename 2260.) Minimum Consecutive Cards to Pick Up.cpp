class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,set<int>> mp;
        vector<int> minimum;
        for(int i=0;i<cards.size();i++)
            mp[cards[i]].insert(i);
        for(auto i:mp)
        {
            int min = INT_MAX;
            auto prev = i.second.begin();
            auto temp = prev;
            auto curr = temp++;
            while(curr != i.second.end())
            {
                if((*curr-*prev) != 0 && min > (*curr-*prev))
                    min = (*curr-*prev);
                prev = curr;
                curr++;
            }
            minimum.push_back(min);
        }
        if(*min_element(minimum.begin(),minimum.end()) != INT_MAX)
            return *min_element(minimum.begin(),minimum.end())+1; 
        return -1;
    }
};