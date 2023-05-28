class Solution {
public:
    string removeTrailingZeros(string num) {
        string updatedNum;
        int end = num.length() - 1;
        int start = 0;
        while(num[end] == '0')
            end--;
        
        while(start <= end)
            updatedNum.push_back(num[start++]);
        
        return updatedNum;
    }
};