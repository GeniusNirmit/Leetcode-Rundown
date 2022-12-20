class Solution {
public:
    int longestMountain(vector<int>& a) {
        int i = 0, max = 0;
        while(a.size()>2 && i<a.size()-2) 
        {
            int j = i + 1;
            if(a[i]<a[j]) 
            {
                while(j<a.size()-1 && a[j]<a[j+1])
                    j++;
                while(j<a.size()-1 && a[j]>a[j+1])
                {
                    j++;
                    if(max<j-i+1)
                        max = j - i + 1; 
                }                        
            }
            i = j;          
        }
        return max;
    }
};