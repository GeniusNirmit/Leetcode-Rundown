class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        vector<int> averages(a.size(), -1);
        long long sum = 0;
        int divide = (2 * k + 1);
        
        for(int i=0; i<a.size(); i++)
        {
            sum += a[i];
            if(i >= divide-1)
            {
                averages[i-k] = sum / divide;
                sum -= a[i-divide+1];    
            }
        }
        return averages;
    }
};