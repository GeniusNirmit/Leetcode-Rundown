class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int counter = 0, min = INT_MAX;
        for(int i=0;i<words.size();i++)   
        {
            if(words[i]==target)
            {
                if(min > abs(startIndex - i))
                    min = abs(startIndex - i);
                if(i < startIndex)
                {
                    if(min > i+words.size()-startIndex)
                        min = i+words.size()-startIndex;
                }
                else
                {
                    if(min > startIndex+words.size()-i)
                        min = startIndex+words.size()-i;
                }
            }
        }
        if(min == INT_MAX)
            min = -1;
        return min;
    }
};