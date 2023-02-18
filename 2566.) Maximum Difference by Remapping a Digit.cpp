class Solution {
public:
    int minMaxDifference(int num) {
        string maxNumber = to_string(num);
        string minNumber = to_string(num);
        char maxNum = maxNumber[0] , minNum = minNumber[0];
        
        for(int i=0;i<maxNumber.size();i++)
        {
            if(maxNumber[i]!='9')
            {
                maxNum = maxNumber[i];
                break;
            }
        }
        for(int i=0;i<maxNumber.size();i++)
        {
            if(maxNumber[i] == maxNum)
                maxNumber[i]='9';
        }
        for(int i=0;i<minNumber.size();i++)
        {
            if(minNumber[i] == minNum)
                minNumber[i]='0';
        }
        return stoi(maxNumber)-stoi(minNumber);
       
    }
};