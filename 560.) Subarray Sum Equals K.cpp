class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int> sumMap;
        int sum = 0;
        int counter = 0;
        sumMap[sum]++;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            if(sumMap.find(sum-k)!=sumMap.end())
                counter += sumMap[sum-k];
            sumMap[sum]++;
        }
        return counter;
    }
};