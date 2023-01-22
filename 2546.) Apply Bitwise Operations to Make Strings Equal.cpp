class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int sOneCounter = 0;
        int targetOneCounter = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
                sOneCounter++;
            if(target[i] == '1')
                targetOneCounter++;
        }
        if(!sOneCounter && targetOneCounter)
            return false;
        if(sOneCounter && !targetOneCounter)
            return false;
        return true;
    }
};