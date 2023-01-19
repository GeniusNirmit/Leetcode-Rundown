class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        long long counter = 0;
        long long goodCounter = 0;
        int j = 0;
        unordered_map<int,int> frequencies;
        for(int i=0;i<a.size();i++)
        {
            frequencies[a[i]]++;
            if(frequencies[a[i]]>=2)
                counter += frequencies[a[i]] - 1;
            while(j <= i && counter >= k)
            {
                goodCounter += a.size() - i;
                frequencies[a[j]]--;
                if(frequencies[a[j]]>=1)
                    counter -= frequencies[a[j]];
                j++;
            }
        }
        return goodCounter;
    }
};