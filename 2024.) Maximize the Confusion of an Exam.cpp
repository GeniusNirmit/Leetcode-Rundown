class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int j = 0,counter = 0,maxTrue = 0,maxFalse = 0;
        for(int i=0;i<answerKey.length();i++)
        {
            if(answerKey[i]=='T')
                counter++;
            if(counter<=k)
            {
                if(maxTrue<i-j+1)
                    maxTrue = i - j + 1;
            }
            else
            {
                while(counter>k)
                {
                    if(answerKey[j]=='T')
                        counter--;
                    j++;
                }
            }
        }

        counter = 0;
        j = 0;
        for(int i=0;i<answerKey.length();i++)
        {
            if(answerKey[i]=='F')
                counter++;
            if(counter<=k)
            {
                if(maxFalse<i-j+1)
                    maxFalse = i - j + 1;
            }
            else
            {
                while(counter>k)
                {
                    if(answerKey[j]=='F')
                        counter--;
                    j++;
                }
            }
        }

        return max(maxTrue,maxFalse);
    }
};