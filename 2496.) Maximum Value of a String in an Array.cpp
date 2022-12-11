class Solution {
public:
    bool isdigit(string &str)
    {
        return str.find_first_not_of("0123456789") == string::npos;
    }
    int maximumValue(vector<string>& strs) {
        int max = 0;
        for(int i=0;i<strs.size();i++)
        {
            if(isdigit(strs[i]))
            {
                if(max < stoll(strs[i]))
                    max = stoll(strs[i]);
            }
            else
            {
                if(max < strs[i].length())
                    max = strs[i].length();
            }
        }
        return max;
    }
};