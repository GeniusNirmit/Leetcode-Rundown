class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> charValue;
        int sum = 0, maxSum = 0;
        for(int i=0; i<s.length(); i++)
        {
            auto ind = chars.find(s[i]);
            if(ind != string::npos)
                charValue.push_back(vals[ind]);
            else
                charValue.push_back((s[i] - 'a') + 1);
        }
        
        for(int i=0; i<charValue.size(); i++)
        {
            sum += charValue[i];
            
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        
        return maxSum;
    }
};