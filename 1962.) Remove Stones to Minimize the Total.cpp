class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        map<int, int> pilesMap;
        int sum = 0;
        for(int i=0;i<piles.size();i++)
            pilesMap[piles[i]]++;
        while(k--)
        {
            auto lastIndexValue = pilesMap.rbegin()->first;
            pilesMap[lastIndexValue]--;
            if(pilesMap[lastIndexValue] == 0)
            {
                auto temp = pilesMap.find(lastIndexValue);
                pilesMap.erase(temp);
            }
            pilesMap[ceil(lastIndexValue/2.0)]++;
        }
        for(auto i:pilesMap)
            sum += i.first*i.second;
        return sum;
    }
};