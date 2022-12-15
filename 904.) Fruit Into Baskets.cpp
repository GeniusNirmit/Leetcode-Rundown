class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> fruitMap;
        int max = 0,j = 0;
        for(int i=0;i<fruits.size();i++)
        {
            fruitMap[fruits[i]]++;
            if(fruitMap.size()>2)
            {
                fruitMap[fruits[j]]--;
                if(fruitMap[fruits[j]]==0)
                    fruitMap.erase(fruits[j]);
                j++;
            }
            if(i-j+1>max)
                max = i-j+1;
        }      
        return max;
    }
};