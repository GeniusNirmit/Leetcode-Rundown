class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,  greater<int>> sortedStones(stones.begin(), stones.end());  
        while(sortedStones.size() != 1)
        {
            int x = *sortedStones.begin();
            sortedStones.erase(sortedStones.begin());
            int y = *sortedStones.begin();
            sortedStones.erase(sortedStones.begin());

            sortedStones.insert(abs(x - y));
        }
        return *sortedStones.begin();
    }
};