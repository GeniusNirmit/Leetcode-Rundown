class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0) {
            return true;
        }
        
        string strNum = to_string(num);

        if(strNum[strNum.size() - 1] == '0') {
            return false;
        }

        return true;
    }
};