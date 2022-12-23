class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        unordered_map<int,int> sumMap;
        int sum = 0;
        int remainder = 0;
        int counter = 0;
        sumMap[sum]++;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            remainder = sum % k;
            if(remainder<0)
                remainder += k;
            if(sumMap.find(remainder)!=sumMap.end())
                counter += sumMap[remainder];
            sumMap[remainder]++;
        }
        return counter;
    }
};