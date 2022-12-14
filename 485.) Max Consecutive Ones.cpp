class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int max = 0;
        int counter = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==1)
                counter++;
            else
            {
                if(max<counter)
                    max = counter;
                counter = 0;
            }
        }
        if(max<counter)
            max = counter;
        return max;
    }
};