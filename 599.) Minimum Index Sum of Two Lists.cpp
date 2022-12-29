class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int min = INT_MAX;
        int sum = 0;
        vector<string> minimumSumList;
        map<string, int> listMap;
        for(int i=0;i<list1.size();i++)
            listMap[list1[i]]=i;
        for(int i=0;i<list2.size() && i<=min;i++)
        {
            if(listMap.find(list2[i])!=listMap.end())
            {
                auto temp = listMap.find(list2[i]);
                sum = i + temp->second;
                if(sum < min)
                {
                    minimumSumList.clear();
                    minimumSumList.push_back(list2[i]);
                    min = sum;
                }
                else if(sum == min)
                    minimumSumList.push_back(list2[i]);
            }
        }
        return minimumSumList;
    }
};