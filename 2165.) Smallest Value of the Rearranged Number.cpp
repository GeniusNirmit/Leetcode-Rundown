class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        long long smallestNum;
        string numStr = to_string(num);
        
        if(numStr[0] == '-')
        {
            sort(numStr.begin()+1, numStr.end());
            reverse(numStr.begin()+1, numStr.end());
            smallestNum = stoll(numStr);
        }
        else
        {
            sort(numStr.begin(), numStr.end());
            int zeroInd = 0;
            while(numStr[zeroInd] == '0')
                zeroInd++;
            swap(numStr[zeroInd], numStr[0]);
            smallestNum = stoll(numStr);
        }
        
        return smallestNum;
    }
};