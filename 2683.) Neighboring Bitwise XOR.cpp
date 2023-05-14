class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> original;
        if(derived[0] == 0)
        {
            original.push_back(1);
            original.push_back(1);
        }
        else
        {
            original.push_back(0);
            original.push_back(1);
        }
        
        for(int i=1; i<derived.size()-1; i++)
        {
            if(derived[i] == 0)
            {
                if(original[i] == 0)
                    original.push_back(0);
                else
                    original.push_back(1);
            }
            else
            {
                if(original[i] == 0)
                    original.push_back(1);
                else
                    original.push_back(0);
            }
        }
        if(derived[derived.size() - 1] == original[derived.size() - 1] ^ original[0])
            return true;
        return false;
    }
};