class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int j = 0;
        int max = 0;
        int counter = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==0)
                counter++;
            if(counter<=k)
            {
                if(max<i-j+1)
                    max = i - j + 1;
            }   
            else
            {
                while(counter>k)
                {
                    if(a[j]==0) 
                        counter--;
                    j++;
                }
            }
        }
        return max;
    }
};