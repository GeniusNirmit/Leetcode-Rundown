class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence[sentence.size()-1])
            return false;
        int i = 1;
        while(i != sentence.length()-1)
        {
            if(sentence[i] == ' ')
            {
                if(sentence[i-1] != sentence[i+1])
                    return false;
            }
            i++;
        }
        return true;
    }
};